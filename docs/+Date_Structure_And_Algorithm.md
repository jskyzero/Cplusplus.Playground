---
layout:     post
title:      "数据结构与算法"
date:       2017-01-20
tags:
    - Code
    - DateStructure
    - Algorithm
    - Cpp
categories:
    - Study
---

本文将概述某学校的数据结构与算法的相关内容，所涉及的到的知识为某老师PDF里面最基本的一部分，可以用来概览知识和复习要点，如果有纰漏之处还请多多指正。

# DSA-C++
# 数据结构与程序设计--C++语言描述

`数据结构` `C++` `HardWorking`

## Introcduction

1. 算法和数据结构至关重要, `Program = Date Structure + Algorithm`
2. `理论,设计,抽象`能力,掌握算法分析和设计方法,`迭代 递归 逐步求精 分治 动态规划 回溯 分枝定界`
3. 计算机与`信息表示 信息处理`,信息的表示和组织将关系到程序的效率
4. 数据结构就是`研究数据的逻辑结构和物理结构以及他们之间的相互关系,并对这种结构定义响应的运算`
5. 逻辑结构:`集合 线性结构(一对一) 树性结构(1对多) 图型结构(多对多)`
6. 数据结构形式定义:`Data-Structure = (D. R)`, 其中,D是数据元素的有限集, R是D上关系的有限集
7. 物理结构:`数据结构在计算机中的表示称为物理结构,又称为储存结构`,(e.g.顺序储存接结构,链式储存结构)
8. 抽象数据类型:`Abstract Data Type = (D, R, P)`, 其中P是对集合基本操作的集合
9. Algorithm: `Finite set of instructions that, it followed, accomplishes a particulat task`
10. Algorithm: `Definiteness, Finiteness, Effectiveness`
11. Good Algorithm: `Correctness, Readability, Robustness, Time & space complexities`
12. Describe Algorithm: `Human language,flow, charts,programming language or pseudocode`
13. `O(1)<O(logn)<O(n)<O(nlogn)<O(n^2 )<O(n^3 ) `  `O(2^n )<O(n!)<O(n^n )`

## Stack

1. Stack, Top, Bottom, LIFO

2. Operation

   ```
   MakeNull(S)		// 使得S称为一个空栈
   Top(S)			// 取得S栈顶元素的值
   Pop(S)			// 弹出S栈顶元素
   Push(S, x)		// 将元素x插入栈顶
   Empty(S)		// 清空一个栈
   ```

3. C++ information hidden

4. More about Abstract Data Types

   ```
   Abstract			数据间相互关系,所需操作
   Data Structure		选择合适实现方式				分析
   Implementation		如何在机器内存中表示数据结构		设计
   Application			解决应用中的细节问题			   实现
   ```

   ​


## Queue

1. Queue, FIFO

2. Operation

   ```
   Constructor operations to construct a queue:
   i. createQueue( )
   // post: creates an empty queue
   ii. enqueue(newItem) // [equivalent to add(newItem)]
   // post: adds newItem at the end of the queue.
   Selector operations to select items of a queue
   i. front( )
   // post: returns the item at the front of the queue. It does not change the
   //queue.
   Predicate operations to test Queues
   i. isEmpty( )
   // post: determines whether a queue is empty
   ii. dequeue( )
   // post: retrieves and removes the item at the front of the queue.
   ```

3. C++ Inheritance

4. Circular Queue

5. Use model in actual event

## Linked Stacks and Queues

1. Pointer: PL/I

2. overflow, pointer, linked list, Contiguous:`连续的`

3. Automatic object:声明就存在的对象,可直接通过其名字引用

   Dynamic object: 运行时才存在的对象,必须通过指针间接引用 

4. C++ pointer: new, delete

5. Node

   ```c++
   Struct Node{
   // data menbers
   	Node_entry 	entry;
   	Node 		*next;
   // constructor
   	Node();
   	Node(Node_entry, Node *add_on=NULL);
   }
   ```

6. 链表:创建,插入,删除,查找

7. ADT求精

   >顺序设计VS.链式设计


## Recurision

1. 递归的定义

   > 1.定义一个对象,又用到这个对象本身
   >
   > 2.定义一个结构,他的每一个部分又是这种结构
   >
   > 3.定义一个过程,在执行过程中又直接的或者间接地地调用过程自己

2. 函数调用,调用时保存调用信息,为调用函数分配数据区,转移控制到入口,返回时需要,保存返回信息,释放数据区,转移控制到入口

3. 递归数,空间需求与递归树的高度成正比

4. 关键步骤->终止规则->算法大纲->终止性->递归树

5. 尾递归

6. 递归算法到非递归算法

   1. 不借助栈的循环结构
   2. 借助栈的循环结构

7. 回溯法

## Lists and Strings

1. ADT list and STL list

   >STL list 只有双向链表的实现版本
   >
   >STL list 不允许随机访问表中的一个位置,只允许随机访问某个数据序列

2. 串是一种特殊的线性表,他的数据结构仅有一个字符组成,与ADT的表的操作有许多不同

3. 串内部表示机制

   1. 定长数组储存
   2. 动态数组
   3. 链式

4. 子串定位运算,又称为模式匹配或者串匹配

   1. BF算法,朴素方法
   2. KMP算法,改进回溯

5. 静态链表

6. 生成树与全排列

7. 广义表

## Binary Tree

1. 二叉树的定义

   >二叉树是由n ( n >= 0 ) 个节点的有限集合构成,此集合可为空集,一个根节点及两棵互不相交的左右子二叉树组成

2. 顺序储存结构/链式储存结构

3. DLR/LDR/LRD (L>R)

4. 线索二叉树

5. Haffman Tree, WPL min => Max weight near root, 哈弗曼编码,判定树

## Graphs

1. 图的定义

   ```
   G = ( V, E ) // 图
   V = { Vi | Vi ∈ DataObject } // 顶点 
   E = { ( Vi, Vj ) | Vi, Vj ∈ V ^ P( Vi, Vj ) } // 边
   ```

2. 矩阵的储存表示

3. 图的遍历

4. 连通性问题

5. 最小生成树 Prim / Kruskal

6. 最短路径

   ​

