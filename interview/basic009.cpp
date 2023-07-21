#include <iostream>
using namespace std;
/**
 * 宏定义和typedef的区别
 */
//文本替换；作用在全局
#define p_char char *

//真正的类型，类型安全检查；作用域有限
typedef char * ptr_char;
