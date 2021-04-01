#ifndef REGISTERMETATYPE_H
#define REGISTERMETATYPE_H

class RegisterMetaType
{
public:
    static RegisterMetaType* instance();

private:
    RegisterMetaType();
    ~RegisterMetaType();

    void init();

};

#endif  //REGISTERMETATYPE_H
