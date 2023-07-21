#include <iostream>
#include <cmath>
using namespace std;

/**
 * 浮点数判等
 * epsilon 绝对值范围
 */

bool isEqual(double a, double b, double epsilon = 1e-12) {
    return fabs(a - b) < epsilon;
}