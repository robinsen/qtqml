#include "settingview.h"
#include "iexport.h"
#include "registermetatype.h"

CSettingView::CSettingView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

CSettingView::~CSettingView()
{

}
