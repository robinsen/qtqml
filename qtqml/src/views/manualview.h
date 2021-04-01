#ifndef MANUALVIEW_H
#define MANUALVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CManualView: public QObject
{
    Q_OBJECT
public:
    explicit CManualView(QObject* parent = Q_NULLPTR);
    ~CManualView();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
