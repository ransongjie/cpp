#include "factory_builder.h"

Factory *FactoryBuilder::buildFactory(enum EFACTORY efactory)
{
    switch (efactory)
    {
    case SHAPE_FACTORY:
        return new ShapeFactory();
        break;
    case COLOR_FACTORY:
        return new ColorFactory();
        break;
    default:
        return nullptr;
        break;
    }
}