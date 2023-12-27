#include <iostream>
#include <vector>
using namespace std;
/*
https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
电话号码的字母组合

string: push_back(c), pop_back()
*/
class Solution
{
private:
    const string letters[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

public:
    vector<string> ans;
    string s;
    /*
    @param idx: 输入数字的索引
    */
    void backtracking(const string &digits, int idx)
    {
        // 深度是输入数字个数
        if (idx == digits.size())
        {
            ans.push_back(s);
            return;
        }
        // 获取输入数字所代表字符串
        string letter = letters[digits[idx] - '0'];
        for (int i = 0; i < letter.size(); i++)
        {
            s.push_back(letter[i]);
            backtracking(digits, idx + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        ans.clear();
        if(digits.size()==0) return ans;
        backtracking(digits, 0); // digits的第0个字符开始
        return ans;
    }
};