#ifndef SINGLEVIEW_H
#define SINGLEVIEW_H

#include "globaldefine.h"

QT_BEGIN_NAMESPACE
class IExport;
QT_END_NAMESPACE


class CSingleView: public QObject
{
    Q_OBJECT
public:
    explicit CSingleView(QObject* parent = Q_NULLPTR);
    ~CSingleView();

private:
    IExport*  m_pIExport = nullptr;

};


#endif
