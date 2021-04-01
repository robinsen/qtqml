#ifndef REALTIMEVIEW_H
#define REALTIMEVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CRealTimeView: public QObject
{
    Q_OBJECT
public:
    explicit CRealTimeView(QObject* parent = Q_NULLPTR);
    ~CRealTimeView();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
