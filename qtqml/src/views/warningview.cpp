#include "warningview.h"
#include "iexport.h"
#include "registermetatype.h"

CWarningView::CWarningView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

CWarningView::~CWarningView()
{

}
