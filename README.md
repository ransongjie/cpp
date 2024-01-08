# cpp
| package   | description     |
|-----------|-----------------|
| basic     | basic knowledge |
| zuo_god   | zuo god         |
| leetcode  | leetcode        |
| interview | interview       |

# basic
| package   | description       |
|-------------|-------------------|
| hello_world | hello world       |
| data_type   | data type         |
| operator    | operator          |
| control     | control structure |
| func        | function          |
| head        | head              |
| oop         | oop               |
| stl         | STL               |
| error       | error exception   |
| template    | generic paradigm  |
| concurrent  | concurrent        |
| cpp17       | cpp17             |
| more        | more              |

# carl
| package   | description   |
|-----------|---------------|
| stack_que     | stack and queue |
| b_tree     | binary tree |

## b_tree
递归三步：
1. 递归入参和出参
2. 递归出口
3. 当前层逻辑

递归和回溯紧挨着
递归中全局变量的作用
递归中返回值的好处

递归是否需要返回值：
- 搜索整棵二叉树 && 不用处理递归返回值，递归函数就不要返回值
- 搜索整棵二叉树 && 需要处理递归返回值，递归函数就需要返回值
- 搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回
## back_track
回溯，深度优先搜索树

回溯模板
```cpp
void backtracking(参数) {
    // 叶子结点
    if (终止条件) {
        存放结果;
        return;
    }
    // 中间结点
    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```

什么时候入参需要startIdx?
- 1个集合求组合
- 多个集合求组合，并且多个集合间互不影响

去重
- 同层去重：必须是 used[i - 1] == false
- 同枝去重：是 used[i - 1] == true

组合问题总结
```text
入参数字不重复，结果集不会重复
可以重复使用相同数字，就i

组合问题III
- 不能无限重复使用相同数字
- 入参数字不重复
- 结果集不重复
组合问题
- 可以无限重复使用相同数字
- 入参数字不重复
- 结果集不重复
组合问题II
- 不能无限重复使用相同数字
- 入参数字重复
- 结果集不重复
```
幂集问题总结
```text
幂集: 入参不包含重复元素
幂集II: 入参可能包含重复元素
```
排列问题总结
```text
排列: 入参不包含重复元素
排列II: 入参可能包含重复元素
```

组合、分割、幂集、排列
- 组合和分割问题都是收集树的叶子节点，幂集问题是找树的所有节点
- 排列问题，每次都要从头开始搜索，不使用startIndex。元素1在[1,2]中已经使用过了，但是在[2,1]中还要在使用一次1，
# zuo_god
todo

# leetcode
| package   | description   |
|-----------|---------------|
| offer_special     | offer special |
