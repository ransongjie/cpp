#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/**
 * 和为 k 的子数组
 */
class Solution010
{
public:
    /**
     * pre+k=cur
     * 散列表记录前缀和出现次数
     */
    int subarraySum(vector<int> &nums, int k)
    {
        int i = 0, n = nums.size(), ans = 0, preSum = 0;
        unordered_map<int, int> sumNum;
        sumNum[preSum] = 1;
        for (; i < n; i++)
        {
            preSum += nums[i];
            if (sumNum.find(preSum - k) != sumNum.end())
            {
                ans += sumNum[preSum - k];
            }
            sumNum[preSum]++; // 默认为0
        }
        return ans;
    }
};