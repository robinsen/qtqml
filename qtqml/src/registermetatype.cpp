#include "registermetatype.h"
#include "resourcemanager.h"
#include "uithememanager.h"
#include "globaldefine.h"
#include <QQmlEngine>
#include <QQmlContext>
#include "equimentmanager.h"
#include "allview.h"
#include "malfunctionview.h"
#include "manualview.h"
#include "dataview.h"
#include "powerview.h"
#include "realtimeview.h"
#include "settingview.h"
#include "singleview.h"
#include "statusview.h"
#include "warningview.h"
#include "reportview.h"
#include "../model/maintoolmodel.h"

RegisterMetaType::RegisterMetaType()
{
    init();
}

RegisterMetaType::~RegisterMetaType()
{
    if (m_pToolModel)
        delete m_pToolModel;
    m_pToolModel = nullptr;
}

RegisterMetaType *RegisterMetaType::instance()
{
    static RegisterMetaType ex;
    return &ex;
}

IExport *RegisterMetaType::getExport()
{
    return m_pIExport;
}

void RegisterMetaType::setQmlContextProperty(QQmlContext *context)
{
    if (context)
    {
        if (m_pToolModel == nullptr)
        {
            m_pToolModel = new MainToolModel;
            initMainToolItem(*m_pToolModel);
            context->setContextProperty("mainModel", m_pToolModel);
        }
    }
}

void RegisterMetaType::init()
{
    m_pIExport = new EquimentManager();

    qRegisterMetaType<ToolType>("ToolType");
    qmlRegisterUncreatableType<ToolItemType>("an.qt.package", 1, 0, "ToolItemType", "Not creatable as it is an enum type");

    qmlRegisterType<CAllView>("an.qt.package", 1, 0, "CAllView");
    qmlRegisterType<CDataView>("an.qt.package", 1, 0, "CDataView");
    qmlRegisterType<CMalfunctionView>("an.qt.package", 1, 0, "CMalfunctionView");
    qmlRegisterType<CManualView>("an.qt.package", 1, 0, "CManualView");
    qmlRegisterType<CPowerView>("an.qt.package", 1, 0, "CPowerView");
    qmlRegisterType<CRealTimeView>("an.qt.package", 1, 0, "CRealTimeView");
    qmlRegisterType<CReportView>("an.qt.package", 1, 0, "CReportView");
    qmlRegisterType<CSettingView>("an.qt.package", 1, 0, "CSettingView");
    qmlRegisterType<CSingleView>("an.qt.package", 1, 0, "CSingleView");
    qmlRegisterType<CStatusView>("an.qt.package", 1, 0, "CStatusView");
    qmlRegisterType<CWarningView>("an.qt.package", 1, 0, "CWarningView");
}

void RegisterMetaType::initMainToolItem(MainToolModel &p)
{
    auto fun = [&](ToolType type, const QString& text, const QString& img,  const QString& selectimg){
        MainToolItem item(type, text, img, selectimg);
        p.addItem(item);
    };

    fun(ToolType::ToolAll, "Test1", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
    fun(ToolType::ToolSingle, "Test2", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
    fun(ToolType::ToolStatus, "Test3", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
    fun(ToolType::ToolData, "Test4", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
    fun(ToolType::ToolPower, "Test5", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
    fun(ToolType::ToolRealTime, "Test6", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
    fun(ToolType::ToolSetting, "Test7", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
    fun(ToolType::ToolMalfunction, "Test8", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
    fun(ToolType::ToolManual, "Test9", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
    fun(ToolType::ToolWarning, "Test10", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
    fun(ToolType::ToolReport, "Test11", GetResPath("collect_4.png"), GetResPath("collect_6.png"));
}
