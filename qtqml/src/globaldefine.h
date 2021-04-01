#ifndef GLOBALDEFINE_H
#define GLOBALDEFINE_H

#include <QObject>
#include <QString>
#include <iostream>

class ToolItemType {
    Q_GADGET
public:
    explicit ToolItemType();

    enum ItemType {
        ToolAll = 0,
        ToolSingle ,
        ToolStatus ,
        ToolData ,
        ToolPower ,
        ToolRealTime ,
        ToolSetting ,
        ToolMalfunction ,
        ToolManual ,
        ToolWarning,
        ToolReport
    };
    Q_ENUM(ItemType)
};
typedef ToolItemType::ItemType ToolType;

struct AllPowerEntity{
    Q_GADGET
    Q_PROPERTY(double wind MEMBER WindSpeed)
    Q_PROPERTY(double active MEMBER ActivePower)
    Q_PROPERTY(double reactive MEMBER ReactivePower)
    Q_PROPERTY(double date MEMBER DateGeneration)
    Q_PROPERTY(double month MEMBER MonthGeneration)
    Q_PROPERTY(double year MEMBER YearGeneration)
    Q_PROPERTY(double total MEMBER TotalGeneration)
public:
    double WindSpeed=0.0;
    double ActivePower=0.0;
    double ReactivePower=0.0;
    double DateGeneration=0.0;
    double MonthGeneration=0.0;
    double YearGeneration=0.0;
    double TotalGeneration=0.0;
};
Q_DECLARE_METATYPE(AllPowerEntity)

#endif  //GLOBALDEFINE_H
