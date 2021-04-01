#include "ResourceManager.h"
#include <QDir>
#include <QDebug>
#include <QImageReader>
#include <QStandardPaths>
#include "uithememanager.h"

QMap<QString, QPixmap*> ResourceManager::m_pixMap;
QMap<QString, QColor> ResourceManager::m_colorMap;
QMap<QString, tagImageInfo*> ResourceManager::m_sharePixampMap;
QMutex ResourceManager::m_mutex;
QMutex ResourceManager::m_lock;
QMutex ResourceManager::m_mutexStorage;
bool   ResourceManager::m_bStop = false;
QThread* ResourceManager::m_thread = nullptr;
QSemaphore ResourceManager::m_sem;
QMap<QString,tagImageStorage> ResourceManager::m_storages;

ResourceManager::ResourceManager()
{
    initLocalImage();
    UIThemeManager::SkinMode theme = UIThemeManager::Instance()->skin();
    if(theme == UIThemeManager::Dark)
    {
        initColorDark();
        initDarkIcon();
    }
    else
    {
        initColor();
        initDeafultIcon();
    }
}

ResourceManager::~ResourceManager()
{
    QMap<QString, QPixmap*>::iterator it;
    for (it = m_pixMap.begin(); it != m_pixMap.end(); it++)
    {
        delete it.value();
    }
    m_pixMap.clear();
}

ResourceManager* ResourceManager::Instance()
{
    static ResourceManager res;
    return &res;
}

QPixmap* ResourceManager::getPixmap(const QString& key)
{
    m_mutex.lock();
    QPixmap* pix = NULL;
    QMap<QString, QPixmap*>::iterator it = m_pixMap.find(key);
    if (it != m_pixMap.end())
    {
        pix = it.value();
    }
    m_mutex.unlock();
    return pix;
}

QColor* ResourceManager::getColor(const QString& key)
{   
    static QColor defaultColor = Qt::transparent;
    QMap<QString, QColor>::iterator it = m_colorMap.find(key);
    if (it != m_colorMap.end())
        return &it.value();
    return &defaultColor;
}

QFileInfoList ResourceManager::getFileList(const QString& path)
{
    QDir dir(path);
    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(int i = 0; i != folder_list.count(); i++)
    {
        QString name = folder_list.at(i).absoluteFilePath();
        QFileInfoList child_file_list = getFileList(name);
        file_list.append(child_file_list);
    }
    return file_list;
}
bool ResourceManager::isExistResource(const QString& key)
{
    bool ret = false;
    m_mutex.lock();
    ret = m_pixMap.contains(key);
    m_mutex.unlock();
    return ret;
}

void ResourceManager::addResource(const QString& key, QPixmap* pix)
{
    if(key.isEmpty())
    {
		if(pix)
			delete pix;
        return;
    }
    m_mutex.lock();
    QString strTemp = key;
    if(strTemp.isEmpty())
    {
        if(pix)
            delete pix;
        return;
    }
    if(m_pixMap.contains(strTemp))
    {
        QPixmap* img = m_pixMap.take(strTemp);
        if(img)
            delete img;
    }
    m_pixMap[strTemp] = pix;
    m_mutex.unlock();
}

void ResourceManager::delResource(const QString& key)
{
    m_mutex.lock();
    if(m_pixMap.contains(key))
    {
        QPixmap* img = m_pixMap.take(key);
        delete img;
    }
    m_mutex.unlock();
}

QPixmap* ResourceManager::getResource(const QString& key)
{
    return getPixmap(key);
}


void ResourceManager::initLocalImage()
{
    QString runDir = QCoreApplication::applicationDirPath() + "/";
    QString resPath = runDir + "/res/default/";
    UIThemeManager::SkinMode theme = UIThemeManager::Instance()->skin();
    if(theme == UIThemeManager::Dark)
        resPath = runDir + "/res/dark/";

    QFileInfoList infoList = getFileList(resPath);
    for (int i=0; i<infoList.count(); i++)
    {
        QPixmap* pix = new QPixmap(infoList.at(i).filePath());
        m_pixMap[infoList.at(i).fileName()] = pix;
    }
}
QPixmap ResourceManager::getImage(const QString& key, const QString& filePath, void* ref)
{
    QPixmap image;
    if(key.isEmpty())
        return image;
    bool bFind = false;
    m_lock.lock();
    if(m_sharePixampMap.contains(key))
    {
        tagImageInfo* info = m_sharePixampMap.value(key);
        if(!info->refList.contains(ref))
        {
            info->m_nRef++;
            info->refList.push_back(ref);
        }
        image = info->pixmap;
        bFind = true;
    }   
    if(!bFind)
    {
        QFile file(filePath);
        if(file.open(QIODevice::ReadOnly))
        {
            bool delImage = false;
            qint64 len = file.size();
            QByteArray arr = file.read(len);
            if(image.loadFromData(arr))
            {
                if(!image.isNull())
                {
                    tagImageInfo* info = new tagImageInfo;
                    info->key = key;
                    info->pixmap = image;
                    info->path = filePath;
                    info->m_nRef = 1;
                    info->refList.push_back(ref);
                    m_sharePixampMap.insert(key,info);
                }
                else
                    delImage = true;
            }
            else //if(len == 0)
                delImage = true;
            file.close();
            if(delImage) //add by zzl 20191212 不是图片文件删除，防止文件存在无法下载
            {
                QFile::remove(filePath);
            }
        }
    }
     m_lock.unlock();

    return image;
}
void  ResourceManager::releaseImage(const QString& key,void* ref)
{
    m_lock.lock();
    if(m_sharePixampMap.contains(key))
    {
        tagImageInfo* info = m_sharePixampMap.value(key);
        if(info->refList.contains(ref))
        {
            info->refList.removeAll(ref);
            info->m_nRef--;
            if(info->m_nRef == 0)
            {
                m_sharePixampMap.take(key);
                //qDebug()<<"realease image key="<<key;
                delete info;
            }
        }
    }
    m_lock.unlock();

}
 void ResourceManager::removeImage(const QString& key)
 {
     m_lock.lock();
     if(m_sharePixampMap.contains(key))
     {
         tagImageInfo* info = m_sharePixampMap.take(key);
         if(info)
             delete info;
     }
     m_lock.unlock();
 }

void ResourceManager::updateImage(const QString &key, const QString &filePath)
{
    m_lock.lock();
    if(m_sharePixampMap.contains(key))
    {
        QPixmap image;
        tagImageInfo* info = m_sharePixampMap.value(key);
        QFile file(filePath);
        if(file.open(QIODevice::ReadOnly))
        {
            qint64 len = file.size();
            QByteArray arr = file.read(len);
            image.loadFromData(arr);
            if(!image.isNull())
            {
                info->pixmap.detach();
                info->key = key;
                info->pixmap = image;
                info->path = filePath;
            }
            file.close();
        }
    }
    m_lock.unlock();
}

void ResourceManager::readImageTheadFun()
{
    while(!m_bStop)
    {
        m_sem.acquire();
        while(!m_bStop)
        {
            tagImageStorage storage;
            bool bHasData = false;
            m_mutexStorage.lock();
            if(m_storages.size() > 0)
            {
                storage = m_storages.first();
                bHasData = true;
            }
            m_mutexStorage.unlock();
            if(bHasData)
            {
                QImageReader reader(storage.filePath);
                QPixmap image = QPixmap::fromImageReader(&reader);
                if(!image.isNull())
                {
                    tagImageInfo* info = new tagImageInfo;
                    info->key = storage.key;
                    info->pixmap = image;
                    info->path = storage.filePath;
                    info->m_nRef = 1;
                    m_lock.lock();
                    m_sharePixampMap.insert(storage.key,info);
                    m_lock.unlock();

                }
                m_mutexStorage.lock();
                m_storages.remove(storage.key);
                m_mutexStorage.unlock();
            }
            else
                break;
            QThread::msleep(5);
        }

    }
}

void ResourceManager::changeThemeSkin(int mode)
{
    UIThemeManager::SkinMode theme = (UIThemeManager::SkinMode)mode;
    if(theme == UIThemeManager::Default)
    {
        initColor();
        initDeafultIcon();
    }
    else if(theme == UIThemeManager::Dark)
    {
        initColorDark();
        initDarkIcon();
    }
}

void ResourceManager::initColor()
{

}

void ResourceManager::initColorDark()
{

}

void ResourceManager::initDeafultIcon()
{
    QString resPath = getResDir();
    QFileInfoList infoList = getFileList(resPath);
    for (int i=0; i<infoList.count(); i++)
    {
        QString key = infoList.at(i).fileName();
        QPixmap* pix = new QPixmap(infoList.at(i).filePath());
        addResource(key,pix);
    }
}

void ResourceManager::initDarkIcon()
{
    QString resPath = getDarkResDir();
    QFileInfoList infoList = getFileList(resPath);
    for (int i=0; i<infoList.count(); i++)
    {
        QString key = infoList.at(i).fileName();
        QPixmap* pix = new QPixmap(infoList.at(i).filePath());
        addResource(key,pix);
    }
}

QString ResourceManager::getAppDataDir()
{
    QString strDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+"/";
    QDir dir(strDir);
    if(!dir.exists())
        dir.mkpath(strDir);
    return strDir;
}

QString ResourceManager::getLogDir()
{
    QString appDateDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QString logdir = appDateDir + "/log/";
    return logdir;
}

QString ResourceManager::mkMutiDir(const QString& path)
{
    QDir dir(path);
    if (dir.exists(path))
    {
        return path;
    }
    QString parentDir = mkMutiDir(path.mid(0,path.lastIndexOf('/')));
    QString dirname = path.mid(path.lastIndexOf('/') + 1);
    QDir parentPath(parentDir);
    if ( !dirname.isEmpty() )
        parentPath.mkpath(dirname);
    return parentDir + "/" + dirname;
}

QString ResourceManager::getResPath(const QString &name)
{
    QString runDir = QCoreApplication::applicationDirPath();
    QString resPath = runDir + "/res/default/";
    UIThemeManager::SkinMode theme = UIThemeManager::Instance()->skin();
    if(theme == UIThemeManager::Dark)
        resPath = runDir + "/res/dark/";
    return "file:/" + resPath + name;
}

QString ResourceManager::getResDir()
{
    QString runDir = QCoreApplication::applicationDirPath() + "/";
    return runDir + "/res/default/";
}

QString ResourceManager::getDarkResDir()
{
    QString runDir = QCoreApplication::applicationDirPath() + "/";
    return runDir + "/res/dark/";
}
