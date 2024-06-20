#ifndef _FACTORY_BUILDER_H_
#define _FACTORY_BUILDER_H_
#include "factory.h"

class FactoryBuilder
{
public:
    Factory *buildFactory(enum EFACTORY efactory);
};
#endif