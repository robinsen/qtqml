#include "statusview.h"
#include "iexport.h"
#include "registermetatype.h"

CStatusView::CStatusView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

CStatusView::~CStatusView()
{

}
