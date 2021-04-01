#ifndef REGISTERMETATYPE_H
#define REGISTERMETATYPE_H
#include <QObject>

QT_BEGIN_NAMESPACE
class IExport;
class QQmlContext;
class MainToolModel;
QT_END_NAMESPACE

#define GetIExportPointer RegisterMetaType::instance()->getExport()

class RegisterMetaType
{
public:
    static RegisterMetaType* instance();

    IExport* getExport();
    void setQmlContextProperty(QQmlContext* context);

private:
    RegisterMetaType();
    ~RegisterMetaType();

    void init();
    void initMainToolItem(MainToolModel& p);


private:
    IExport* m_pIExport = nullptr;

    MainToolModel*   m_pToolModel = nullptr;
};

#endif  //REGISTERMETATYPE_H
