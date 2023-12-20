#include <iostream>
#include <stack>
using namespace std;

/**
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
 * 删除字符串中的所有相邻重复项
 * 遍历元素与栈顶元素是否相同
 * reverse(s.begin(),s.end())
 */
class Solution
{
public:
    string removeDuplicates(string S)
    {
        // 遍历元素与栈顶元素对比
        int size = S.size();
        stack<int> stk;
        for (int i = 0; i < size; i++)
        {
            if (stk.empty() || stk.top() != S[i])
            {
                stk.push(S[i]);
            }
            else
            {
                stk.pop();
            }
        }
        // 栈》string
        string ans = "";
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        // 反转string
        return ans;
    }
};