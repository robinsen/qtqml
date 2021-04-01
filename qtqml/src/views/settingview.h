#ifndef SETTINGVIEW_H
#define SETTINGVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CSettingView: public QObject
{
    Q_OBJECT
public:
    explicit CSettingView(QObject* parent = Q_NULLPTR);
    ~CSettingView();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
