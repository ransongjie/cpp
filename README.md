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
什么使用入参需要startIdx?
- 1个集合求组合
- 多个集合求组合，并且多个集合间互不影响

回溯，深度有限搜索树

回溯三步
1. 入参出参
2. 深度
3. 结点

回溯模板
```cpp
void backtracking(参数) {
    // 叶子结点结果
    if (终止条件) {
        存放结果;
        return;
    }
    // 结点元素数量
    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```
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

# zuo_god
todo

# leetcode
| package   | description   |
|-----------|---------------|
| offer_special     | offer special |
