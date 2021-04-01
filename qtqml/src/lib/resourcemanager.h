#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QMutex>
#include <QFileInfoList>
#include <QPixmap>
#include <QSemaphore>
#include <QThread>

#define GetResPath(name) ResourceManager::Instance()->getResPath(name)

struct tagImageInfo
{
    QPixmap pixmap;
    QString key;
    QString path;
    QList<void*> refList; //引用者
    uint    m_nRef = 1;
};

struct tagImageStorage
{
    QString key;
    QString filePath;
};

class ResourceManager
{
private:
    ResourceManager();
    ~ResourceManager();
public:
    static ResourceManager* Instance();
    QPixmap* getPixmap(const QString& key);
    QColor* getColor(const QString& key);
    void addResource(const QString& key, QPixmap* pix);
    void delResource(const QString& key);
    bool isExistResource(const QString& key);
    QPixmap* getResource(const QString& key);
    int getColorCount(){return 12;}
    QPixmap getImage(const QString& key, const QString& filePath, void* ref);
    void    releaseImage(const QString& key,void* ref);
    void    removeImage(const QString& key);
    void    updateImage(const QString&key, const QString& filePath);
    void readImageTheadFun();
    void changeThemeSkin(int);

    QString getResDir();
    QString getDarkResDir();
    QString getAppDataDir();
    QString getLogDir();
    QString mkMutiDir(const QString& path);
    QString getResPath(const QString& name);
private:
    QFileInfoList getFileList(const QString& path);
    void initLocalImage();
    void initColor();
    void initColorDark();
    void initDeafultIcon();
    void initDarkIcon();
private:
    static QMap<QString, QPixmap*> m_pixMap;
    static QMap<QString, QColor> m_colorMap;
    static QMap<QString,tagImageInfo*> m_sharePixampMap;
    static QMutex m_mutex;
    static QMutex m_lock;
    static QMutex m_mutexStorage;
    static QSemaphore m_sem;
    static QThread* m_thread;
    static bool m_bStop;
    static QMap<QString,tagImageStorage> m_storages;

    QString m_runDir;
};



#endif // RESOURCEMANAGER_H
