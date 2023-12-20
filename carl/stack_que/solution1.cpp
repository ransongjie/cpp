#include <iostream>
#include <stack>
using namespace std;

/**
 * https://leetcode.cn/problems/implement-queue-using-stacks
 * 用栈模拟队列
 * stack: push(int x) pop() top() empty()
 */
class MyQueue
{
public:
    stack<int> stackIn;
    stack<int> stackOut;

    MyQueue() {

    }

    void push(int x)
    {
        stackIn.push(x);
    }

    int pop()
    {
        if (stackOut.empty())
        {
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int ans = stackOut.top();
        stackOut.pop();
        return ans;
    }

    int peek()
    {
        int ans = pop();    // 从stackOut中出
        stackOut.push(ans); // 再放入stackOut中
        return ans;
    }

    bool empty()
    {
        return stackIn.empty() && stackOut.empty();
    }
};