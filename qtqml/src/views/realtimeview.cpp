#include "realtimeview.h"
#include "iexport.h"
#include "registermetatype.h"

CRealTimeView::CRealTimeView(QObject* parent)
    :QObject(parent)
{
    m_pIExport = GetIExportPointer;
}

CRealTimeView::~CRealTimeView()
{

}
