#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 数组中和为0的三个数
 */
class Solution007
{
public:
    /**
     * 排序
     * 两数之和=target
     * 首尾双指针
     * 去重
     */
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size(), target = 0, k = 0, j = 0, sum = 0;
        for (; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            target = 0 - nums[i];
            k = i + 1;
            j = n - 1;
            while (k < j)
            {
                sum = nums[k] + nums[j];
                if (target == sum)
                {
                    ans.push_back({nums[i], nums[k], nums[j]});
                    while (k < j && nums[k] == nums[++k])
                        ;
                    while (k < j && nums[j] == nums[--j])
                        ;
                }
                else if (target > sum)
                {
                    k++;
                }
                else
                {
                    j--;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution007 *s = new Solution007();
    vector<int> nums = {1, -1, -1, 0};
    vector<vector<int>> rs = s->threeSum(nums);
    cout << endl;
}