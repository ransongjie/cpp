#include <iostream>
#include <vector>
using namespace std;

/*
https://leetcode.cn/problems/restore-ip-addresses/
复原 IP 地址
*/
class Solution
{
private:
    vector<string> ans; // 记录结果
    /*
    @param: startIndex 搜索的起始位置
    @param: pointNum 添加逗点的数量
    */
    void backtracking(string &s, int startIdx, int pointNum)
    {
        // 添加了3个.号，需要判断第4段是否合法
        if (pointNum == 3)
        {
            if (isValid(s, startIdx, s.size() - 1))
            {
                ans.push_back(s);
            }
            return;
        }

        // startIdx到i
        for (int i = startIdx; i < s.size(); i++)
        {
            if (isValid(s, startIdx, i))
            {
                // 插入.
                pointNum++;
                s.insert(s.begin() + i + 1, '.');
                backtracking(s, i + 2, pointNum); // 以前是+1，这里已插入.
                // 删除.
                pointNum--;
                s.erase(s.begin() + i + 1);
            }
            // 一段不合法，整个字符串不可能合法
            else
            {
                break;
            }
        }
    }

    /*
    判断字符串s[start, end]所组成的数字是否合法
    */
    bool isValid(const string &s, int start, int end)
    {
        if (start > end)
        {
            return false;
        }

        // 以0开头的数字不合法。如 01
        // 仅有1个0的数字合法
        if (s[start] == '0' && start != end)
        {
            return false;
        }

        // num>255不合法
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            // 出现非数字
            if (s[i] > '9' || s[i] < '0')
            {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255)
            {
                return false;
            }
        }

        return true;
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        ans.clear();
        // 无法切成4段合法数字
        if (s.size() < 4 || s.size() > 12)
        {
            return ans;
        }
        backtracking(s, 0, 0);
        return ans;
    }
};