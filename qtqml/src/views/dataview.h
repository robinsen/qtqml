#ifndef DATAVIEW_H
#define DATAVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CDataView: public QObject
{
    Q_OBJECT
public:
    explicit CDataView(QObject* parent = Q_NULLPTR);
    ~CDataView();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
