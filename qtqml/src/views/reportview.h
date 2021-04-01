#ifndef REPORTVIEW_H
#define REPORTVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CReportView: public QObject
{
    Q_OBJECT
public:
    explicit CReportView(QObject* parent = Q_NULLPTR);
    ~CReportView();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
