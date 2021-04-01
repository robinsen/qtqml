#include "uithememanager.h"
#include <QSettings>
#include <QStandardPaths>
#include <QDir>

UIThemeManager::UIThemeManager()
{
    QString strDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+"/";
    QDir dir(strDir);
    if(!dir.exists())
        dir.mkpath(strDir);
    QString iniFileName = strDir+QLatin1String("config.ini");
    QSettings settings(iniFileName,QSettings::IniFormat);
    QString skinStr = settings.value(QStringLiteral("/Theme/skin"),QStringLiteral("default")).toString();
    if(skinStr.compare(QLatin1String("default"),Qt::CaseInsensitive) == 0)
        m_curSkin = Default;
    else if(skinStr.compare(QLatin1String("dark"),Qt::CaseInsensitive) == 0)
        m_curSkin = Dark;
    else
       m_curSkin = Default;
}

UIThemeManager *UIThemeManager::Instance()
{
    static UIThemeManager im;
    return &im;
}

UIThemeManager::SkinMode UIThemeManager::skin()
{
    return m_curSkin;
}

void UIThemeManager::setSkin(UIThemeManager::SkinMode style)
{
    QString skinStr = "default";
    if(style == Dark)
        skinStr = "dark";
    QString strDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+"/";
    QDir dir(strDir);
    if(!dir.exists())
        dir.mkpath(strDir);
    QString iniFileName = strDir+"config.ini";
    QSettings settings(iniFileName,QSettings::IniFormat);
    settings.setValue("/Theme/skin",skinStr);
    m_curSkin = style;
    emit skinChanged();
}

