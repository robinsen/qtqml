#include "dataview.h"
#include "iexport.h"
#include "registermetatype.h"

CDataView::CDataView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

CDataView::~CDataView()
{

}
