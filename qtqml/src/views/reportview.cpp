#include "reportview.h"
#include "iexport.h"
#include "registermetatype.h"

CReportView::CReportView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

CReportView::~CReportView()
{

}
