#ifndef _PACKING_H_
#define _PACKING_H_
#include <string>

class Packing{
public:
    virtual std::string pack()=0;    
};

class Bottle: public Packing{
public:
    virtual std::string pack() override;
};

class Wrapper: public Packing{
public:
    virtual std::string pack() override;
};

#endif