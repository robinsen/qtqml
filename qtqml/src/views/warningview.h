#ifndef WARNINGVIEW_H
#define WARNINGVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CWarningView: public QObject
{
    Q_OBJECT
public:
    explicit CWarningView(QObject* parent = Q_NULLPTR);
    ~CWarningView();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
