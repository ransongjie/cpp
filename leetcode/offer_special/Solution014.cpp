#include <iostream>
#include <vector>
using namespace std;

class Solution014
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int i = 0, j = 0, m = s1.length(), n = s2.length();
        vector<int> cnts(26); //
        if (m > n)
        {
            return false;
        }
        for (auto &c : s1) //
        { 
            cnts[c - 'a']--;
        }
        while (j < n)
        {
            cnts[s2[j] - 'a']++;
            while (i <= j && cnts[s2[j] - 'a'] > 0)
            {
                cnts[s2[i] - 'a']--;
                i++;
            }
            if (j - i + 1 == m)
            {
                return true;
            }
            j++;
        }
        return false;
    }
};
