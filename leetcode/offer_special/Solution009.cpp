#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution009
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int i = 0, j = 0, n = nums.size(), ans = 0, mul = 1;
        while (j < n)
        {
            mul *= nums[j];
            while (i <= j && mul >= k)
            {
                mul /= nums[i];
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
};