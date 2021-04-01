#include "export.h"

Export::Export()
{
    registerMetaType();
}

Export::~Export()
{

}

Export *Export::instance()
{
    static Export ex;
    return &ex;
}

void Export::registerMetaType()
{

}
