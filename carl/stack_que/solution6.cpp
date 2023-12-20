#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;
/**
 * https://leetcode.cn/problems/sliding-window-maximum/
 * 单调队列
 * 内部类 不依赖外部类，无静态内部类
 * deque: empty(), front(), back(), pop_front(), pop_back(), push_front(), push_back()
 */
class Solution
{
private:
    class MyQueue
    { // 单调队列（从大到小）
    public:
        deque<int> dque;
        // value==front_value才可以弹出，因为之前可能已经弹出了value
        void pop(int value)
        {
            if (!dque.empty() && value == dque.front())
            {
                dque.pop_front();
            }
        }
        // 从左往右，单调递减
        void push(int value)
        {
            while (!dque.empty() && value > dque.back())
            {
                dque.pop_back();
            }
            dque.push_back(value);
        }

        int front()
        {
            return dque.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        MyQueue myque;
        // 添加k个元素
        for (int i = 0; i < k; i++)
        {
            myque.push(nums[i]);
        }
        ans.push_back(myque.front());
        int size = nums.size();
        // 处理后续元素，pop1个，push1个，获得1个结果
        for (int i = k; i < size; i++)
        {
            myque.pop(nums[i - k]); // i-k
            myque.push(nums[i]);
            ans.push_back(myque.front());
        }
        return ans;
    }
};