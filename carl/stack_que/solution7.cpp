#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
/**
 * https://leetcode.cn/problems/top-k-frequent-elements/
 *
 * 前 K 个高频元素
 *
 * unordered_map:
 * 若该key存在，则访问取得value值；
 * 若该key不存在，访问仍然成功，取得value对象默认构造的值
 *
 * priority_queue: #include <queue>
 */
class Solution
{
public:
    // 自定义比较器，根据value频率从小到大排序
    class Mycomparison
    {
    public:
        // map<pair>
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 使用unordered_map统计每个数字出现的频率
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++; // key不存在返回value默认值
        }
        // 定义小根堆，迭代umap根据频率value排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, Mycomparison> pque;
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++)
        { // map iterator, 所属类::成员, it++
            pque.push(*it);
            // 固定大小为k的小根堆
            if (pque.size() > k)
            {
                pque.pop();
            }
        }

        // 找出前k高频率的key，从大到小放到ans中，小根堆堆顶是小值
        vector<int> ans(k); // vector有参构造大小为k
        for (int i = k - 1; i >= 0; i--)
        {
            ans[i] = pque.top().first; // pque<pair<int,int>>
            pque.pop();
        }
        return ans;
    }
};