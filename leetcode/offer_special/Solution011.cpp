#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 0 和 1 个数相同的子数组
 * 连续子数组的最大长度
 */
class Solution011
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int i = 0, n = nums.size(), preSum = 0, ans = 0;
        unordered_map<int, int> sumIdx;
        sumIdx[preSum] = -1;
        for (; i < n; i++)
        {
            if (nums[i] == 0)
            {
                preSum--;
            }
            else
            {
                preSum++;
            }
            if (sumIdx.find(preSum) != sumIdx.end())
            {
                ans = max(ans, i - sumIdx[preSum]);
            }
            else
            {
                sumIdx[preSum] = i;
            }
        }
        return ans;
    }
};