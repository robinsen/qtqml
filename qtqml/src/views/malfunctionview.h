#ifndef MALFUNCTIONVIEW_H
#define MALFUNCTIONVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CMalfunctionView: public QObject
{
    Q_OBJECT
public:
    explicit CMalfunctionView(QObject* parent = Q_NULLPTR);
    ~CMalfunctionView();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
