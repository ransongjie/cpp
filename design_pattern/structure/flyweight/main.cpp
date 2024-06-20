#include "shape.h"
#include <iostream>
#include <random>
std::string randomColor();
float randomFloat();

const std::string colors[] = {"Red", "Green", "Blue", "White", "Black"};

// g++ *.cpp
int main()
{

    // 模拟创建大量对象
    for (int i = 0; i < 1000; i++)
    {
        Circle *circle = ShapeFactory::getCircle(randomColor());
        circle->setX(randomFloat());
        circle->setY(randomFloat());
        circle->setRadius(randomFloat());
    }

    std::cout << ShapeFactory::csMap.size() << std::endl; // 5

    return 0;
}

std::string randomColor()
{
    // 创建随机数生成器
    std::mt19937 generator(std::random_device{}());

    // 定义分布范围，这里生成0到9的随机数
    std::uniform_int_distribution<int> distribution(0, 4); // [0,4]

    // 生成随机数
    int random_number = distribution(generator);

    return colors[random_number];
}

float randomFloat()
{
    // 创建随机数生成器
    std::mt19937 generator(std::random_device{}());

    // 定义浮点数的分布范围，例如0.0到1.0之间
    std::uniform_real_distribution<float> distribution(0.0, 100.0);

    // 生成随机浮点数
    float random_number = distribution(generator);

    return random_number;
}