#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 和大于等于 target 的最短子数组
 */
class Solution008
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int i = 0, j = 0, ans = INT_MAX, n = nums.size(), sum = 0;
        while (j < n)
        {
            sum += nums[j];
            while (sum >= s)
            {
                ans = min(ans, j - i + 1);
                sum -= nums[i];
            }
            j++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};