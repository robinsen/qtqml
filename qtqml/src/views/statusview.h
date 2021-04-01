#ifndef STATUSVIEW_H
#define STATUSVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CStatusView: public QObject
{
    Q_OBJECT
public:
    explicit CStatusView(QObject* parent = Q_NULLPTR);
    ~CStatusView();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
