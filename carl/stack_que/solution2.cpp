#include<iostream>
#include<queue>
using namespace std;
/**
 * https://leetcode.cn/problems/implement-stack-using-queues/
 * 用队列模拟栈
 * queue: push, pop, front, back, empty
 */
class MyStack{
public:
    queue<int> que;
    queue<int> bkq;

    MyStack(){}

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size=que.size();
        // 但size-1个元素备份到bkq中，留下的最后一个元素就是结果
        size--;
        while(size--){
            bkq.push(que.front());
            que.pop();
        }
        int ans=que.front();
        que.pop();
        que=bkq;// 拷贝构造函数
        while(!bkq.empty()){// 清空bkq
            bkq.pop();
        }
        return ans;
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }
};