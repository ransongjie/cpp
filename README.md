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

# zuo_god
todo

# leetcode
| package   | description   |
|-----------|---------------|
| offer_special     | offer special |
