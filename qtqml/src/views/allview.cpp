#include "allview.h"
#include "iexport.h"
#include "registermetatype.h"

CAllView::CAllView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

AllPowerEntity &CAllView::getAllPower()
{
    AllPowerEntity tmp;
    if (m_pIExport)
        return m_pIExport->getAllPowerInfo();
    return tmp;
}
