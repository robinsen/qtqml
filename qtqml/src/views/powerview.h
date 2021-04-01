#ifndef POWERVIEW_H
#define POWERVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CPowerView: public QObject
{
    Q_OBJECT
public:
    explicit CPowerView(QObject* parent = Q_NULLPTR);
    ~CPowerView();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
