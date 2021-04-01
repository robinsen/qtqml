#ifndef UITHEMEMANAGER_H
#define UITHEMEMANAGER_H

#include <QObject>

class UIThemeManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(UIThemeManager)
    Q_ENUMS(SkinMode)
    Q_PROPERTY(SkinMode themeMode READ skin WRITE setSkin)
public:
    enum SkinMode
    {
        Default,
        Dark
    };

    static UIThemeManager* Instance();

    //获取当前IM主题模式
    SkinMode skin();

    void setSkin(SkinMode style);

signals:
    void skinChanged();
private:
    UIThemeManager();
    SkinMode                 m_curSkin;
};

#endif // UITHEMEMANAGER_H
