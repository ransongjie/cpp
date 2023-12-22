#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/**
 * https://leetcode.cn/problems/evaluate-reverse-polish-notation/
 * 逆波兰表达式求值
 * switch 不支持string
 * stoll: string 》long long stoll(), #include <string>
 * vector<string> vec: 
 * clear(), vec[i], vec.push_back(), vec.push_front(), vec.size()
 * resize(size), begin(), end()
 */

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int size = tokens.size();
        stack<long long> stk;
        // 遍历字符串
        for (int i = 0; i < size; i++)
        {
            // 遍历元素是运算符，出栈两个元素计算，计算结果入栈
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long a = stk.top();
                stk.pop();
                long long b = stk.top();
                stk.pop();
                // b - a，先出栈的放在右边
                if (tokens[i] == "+")
                {
                    stk.push(b + a);
                }
                if (tokens[i] == "-")
                {
                    stk.push(b - a);
                }
                if (tokens[i] == "*")
                {
                    stk.push(b * a);
                }
                if (tokens[i] == "/")
                {
                    stk.push(b / a);
                }
            }
            // 遍历元素是数字，入栈
            else
            {
                stk.push(stoll(tokens[i]));
            }
        }

        // 栈中最后一个字符
        long long ans = stk.top();
        stk.pop();
        return ans;
    }
};