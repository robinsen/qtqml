#include "malfunctionview.h"
#include "iexport.h"
#include "registermetatype.h"

CMalfunctionView::CMalfunctionView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

CMalfunctionView::~CMalfunctionView()
{

}
