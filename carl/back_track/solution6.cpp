#include <iostream>
#include <vector>
using namespace std;

/*
https://leetcode.cn/problems/palindrome-partitioning/
分割回文串
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
*/
class Solution
{
private:
    vector<vector<string>> ans;
    vector<string> path; // 存放已经回文的子串
    void backtracking(const string &s, int startIdx)
    {
        // 叶子结点
        if (startIdx == s.length())
        {
            ans.push_back(path);
            return;
        }
        // 中间结点
        for (int i = startIdx; i < s.length(); i++)
        {
            if (isPalindrome(s, startIdx, i))
            {
                string p = s.substr(startIdx, i - startIdx + 1);
                path.push_back(p);
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    bool isPalindrome(const string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        path.clear();
        ans.clear();
        backtracking(s, 0);
        return ans;
    }
};