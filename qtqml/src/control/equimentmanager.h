#ifndef EQUIMENTMANAGER_H
#define EQUIMENTMANAGER_H

#include "iexport.h"

class EquimentManager: public QObject, public IExport
{
    Q_OBJECT
public:
    explicit EquimentManager(QObject* parent = Q_NULLPTR);
    ~EquimentManager();

    virtual AllPowerEntity& getAllPowerInfo();

};

#endif  //EXPORT_H
