#ifndef EXPORT_H
#define EXPORT_H

#include "export.h"

class Export
{
public:
    static Export* instance();

private:
    Export();
    ~Export();

    void registerMetaType();

};

#endif  //EXPORT_H
