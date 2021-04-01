#include "singleview.h"
#include "iexport.h"
#include "registermetatype.h"

CSingleView::CSingleView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

CSingleView::~CSingleView()
{

}
