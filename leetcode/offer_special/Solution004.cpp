#include <iostream>
#include <vector>
using namespace std;

/**
 * 只出现一次的数字
 * 数字只出现1次和3次
 */
class Solution4
{
public:
    int singleNumber(vector<int> &nums)
    {
        int r = 0;
        for (int i = 0; i < 32; i++)
        {
            int total = 0;
            for (int num : nums)
            {
                total += ((num >> i) & 1);
            }
            if (total % 3)
            {
                r |= (1 << i);
            }
        }
        return r;
    }
};