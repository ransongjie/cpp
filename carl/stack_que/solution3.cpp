#include <iostream>
#include <stack>
using namespace std;

/**
 * https://leetcode.cn/problems/valid-parentheses/
 * 有效的括号
 * 无效括号的情况
 * 1. 栈顶字符与遍历字符不匹配
 * 2. 栈空但字符未遍历完成
 * 3. 栈非空但字符遍历完成
 * string: size() str[i]
 */
class Solution
{
public:
    bool isValid(string s)
    {
        int size = s.size();
        stack<char> stack;
        for (int i = 0; i < size; i++)
        {
            bool a = false;
            switch (s[i])
            {
            case '(':
                stack.push(')');
                a = true;
                break;
            case '[':
                stack.push(']');
                a = true;
                break;
            case '{':
                stack.push('}');
                a = true;
                break;
            }
            if (!a)
            {
                // 栈空但字符未遍历完成
                if (stack.empty())
                {
                    return false;
                }
                // 栈顶字符与遍历字符不匹配
                if (stack.top() != s[i])
                {
                    return false;
                }
                // 栈顶字符和遍历字符匹配
                stack.pop();
            }
        }
        // 栈非空但字符遍历完成
        return stack.empty();
    }
};