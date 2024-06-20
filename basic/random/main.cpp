#include <iostream>
#include <random>

void test1(int);
void test2();

int main()
{
    test1(9);
    test2();

    return 0;
}

//[0,upper]的随机整数
//[0,9]的随机整数
void test1(int upper)
{
    // 创建随机数生成器
    std::mt19937 generator(std::random_device{}());
    // std::mt19937 generator(123); // 使用固定种子

    // 定义分布范围，这里生成0到9的随机数
    std::uniform_int_distribution<int> distribution(0, upper);

    // 生成随机数
    int random_number = distribution(generator);

    // 输出随机数
    std::cout << "Random number between 0 and 9: " << random_number << std::endl;
}

void test2()
{
    // 创建随机数生成器
    std::mt19937 generator(std::random_device{}());

    // 定义浮点数的分布范围，例如0.0到1.0之间
    std::uniform_real_distribution<float> distribution(0.0, 1.0);

    // 生成随机浮点数
    float random_number = distribution(generator);

    // 输出随机浮点数
    std::cout << "Random floating point number between 0.0 and 1.0: " << random_number << std::endl;
}