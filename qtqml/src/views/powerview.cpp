#include "powerview.h"
#include "iexport.h"
#include "registermetatype.h"

CPowerView::CPowerView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

CPowerView::~CPowerView()
{

}
