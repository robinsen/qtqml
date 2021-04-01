#include "manualview.h"
#include "iexport.h"
#include "registermetatype.h"

CManualView::CManualView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

CManualView::~CManualView()
{

}
