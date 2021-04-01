#ifndef ALLVIEW_H
#define ALLVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CAllView: public QObject
{
    Q_OBJECT
public:
    explicit CAllView(QObject* parent = Q_NULLPTR);

    Q_INVOKABLE AllPowerEntity& getAllPower();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
