#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
/*
https://leetcode.cn/problems/reconstruct-itinerary/
重新安排行程
安排飞机航程
*/
class Solution
{
private:
    /*
    unordered_map<出发机场, map<到达机场, 航班次数>> targets
    map，具有排序和增删元素的功能
    航班次数, 从出发机场》到达机场的航班次数
    */
    unordered_map<string, map<string, int>> targets;
    /*
    就是深度优先搜索
    @param: ticketNum 机票数量，航班数量
    @param: ans 结果
    */
    bool backtracking(int ticketNum, vector<string> &ans)
    {
        // 航班数量+1==机场数量，边数量+1==点数量
        if (ans.size() == ticketNum + 1)
        {
            return true;
        }
        // 从ans末尾机场出发，遍历能够到达的机场
        for (pair<const string, int> &next : targets[ans[ans.size() - 1]])
        {
            // 还能够飞过next机场
            if (next.second > 0)
            {
                ans.push_back(next.first);
                next.second--; // 飞过next机场1次
                // 找到可行航线立即返回
                if (backtracking(ticketNum, ans))
                {
                    return true;
                }
                next.second++;
                ans.pop_back();
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        targets.clear();
        vector<string> ans;
        // 记录映射关系
        for (const vector<string> &vec : tickets)
        {
            //{key:{key:cnt}}
            targets[vec[0]][vec[1]]++;
        }
        // 起始机场
        ans.push_back("JFK");
        backtracking(tickets.size(), ans);
        return ans;
    }
};