#include "./include/shape.h"
#include <iostream>

//g++ *.cpp -I ./include -std=c++11
int main()
{
    // 数据库
    ShapeCache::loadCache();
    // 模拟从数据库获取对象
    Shape *shape1 = ShapeCache::getShape(1);
    Shape *shape2 = ShapeCache::getShape(2);
    std::cout << "Shape: " << shape1->getType() << std::endl;
    std::cout << "Shape: " << shape2->getType() << std::endl;

    return 0;
}