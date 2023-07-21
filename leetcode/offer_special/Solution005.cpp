#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution5
{
public:
    int maxProduct(vector<string> &words)
    {
        int r = 0, i = 0, j = 0, n = words.size();
        for (; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                if (!hasSameChar(words[i], words[j]))
                {
                    r = max(r, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return r;
    }

private:
    bool hasSameChar(string &s1, string &s2)
    {
        int a = 0, b = 0;
        for (auto c : s1)
        {
            a |= (1 << c - 'a');
        }
        for (auto c : s2)
        {
            b |= (1 << c - 'a');
        }
        return (a & b);
    }
};