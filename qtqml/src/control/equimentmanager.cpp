#include "equimentmanager.h"

EquimentManager::EquimentManager(QObject* parent)
    :QObject(parent)
{

}

EquimentManager::~EquimentManager()
{

}

AllPowerEntity& EquimentManager::getAllPowerInfo()
{
    AllPowerEntity all;
    all.WindSpeed = 2.0;
    all.ActivePower = 5.0;
    all.ReactivePower = 12.0;
    all.DateGeneration = 2.0;

    return all;
}
