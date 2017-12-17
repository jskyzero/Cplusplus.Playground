---
layout: post
title:  排序算法
date:   2017/02/05
updated: 2017/02/08
tags:
    - Code
    - Algorithm
categories:
    - Code
---

关于最基础最基础的排序算法，虽然我现在也不会写一个快排:(
  
# SORT

`20161107` `Algorithm`

## TOTAL

### 稳定的排序

- [冒泡排序](https://zh.wikipedia.org/wiki/%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F)（bubble sort）— O(*n*2)
- [插入排序](https://zh.wikipedia.org/wiki/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F)（insertion sort）—O(*n*2)
- [鸡尾酒排序](https://zh.wikipedia.org/wiki/%E9%B8%A1%E5%B0%BE%E9%85%92%E6%8E%92%E5%BA%8F)（cocktail sort）—O(*n*2)
- [桶排序](https://zh.wikipedia.org/wiki/%E6%A1%B6%E6%8E%92%E5%BA%8F)（bucket sort）—O(*n*)；需要O(*k*)额外空间
- [计数排序](https://zh.wikipedia.org/wiki/%E8%AE%A1%E6%95%B0%E6%8E%92%E5%BA%8F)（counting sort）—O(*n*+*k*)；需要O(*n*+*k*)额外空间
- [归并排序](https://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F)（merge sort）—O(*n* log *n*)；需要O(*n*)额外空间
- 原地[归并排序](https://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F)— O(*n* log2 *n*)如果使用最佳的现在版本
- [二叉排序树](https://zh.wikipedia.org/wiki/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91)排序（binary tree sort）— O(*n* log *n*)期望时间；O(*n*2)最坏时间；需要O(*n*)额外空间
- [鸽巢排序](https://zh.wikipedia.org/wiki/%E9%B8%BD%E5%B7%A2%E6%8E%92%E5%BA%8F)（pigeonhole sort）—O(*n*+*k*)；需要O(*k*)额外空间
- [基数排序](https://zh.wikipedia.org/wiki/%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F)（radix sort）—O(*n*·*k*)；需要O(*n*)额外空间
- [侏儒排序](https://zh.wikipedia.org/w/index.php?title=%E4%BE%8F%E5%84%92%E6%8E%92%E5%BA%8F&action=edit&redlink=1)（gnome sort）— O(*n*2)
- [图书馆排序](https://zh.wikipedia.org/w/index.php?title=%E5%9C%96%E6%9B%B8%E9%A4%A8%E6%8E%92%E5%BA%8F&action=edit&redlink=1)（library sort）— O(*n* log *n*)期望时间；O(*n*2)最坏时间；需要(1+ε)*n*额外空间
- [块排序](https://zh.wikipedia.org/w/index.php?title=%E5%A1%8A%E6%8E%92%E5%BA%8F&action=edit&redlink=1)（block sort）— O(*n* log *n*)

### 不稳定的排序

- [选择排序](https://zh.wikipedia.org/wiki/%E9%81%B8%E6%93%87%E6%8E%92%E5%BA%8F)（selection sort）—O(*n*2)
- [希尔排序](https://zh.wikipedia.org/wiki/%E5%B8%8C%E5%B0%94%E6%8E%92%E5%BA%8F)（shell sort）—O(*n* log2 *n*)如果使用最佳的现在版本
- [Clover排序算法](https://zh.wikipedia.org/w/index.php?title=Clover%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95&action=edit&redlink=1)（Clover sort）—O(n)期望时间，O(n2)最坏情况
- [梳排序](https://zh.wikipedia.org/wiki/%E6%A2%B3%E6%8E%92%E5%BA%8F)— O(*n* log *n*)
- [堆排序](https://zh.wikipedia.org/wiki/%E5%A0%86%E6%8E%92%E5%BA%8F)（heap sort）—O(*n* log *n*)
- [平滑排序](https://zh.wikipedia.org/w/index.php?title=%E5%B9%B3%E6%BB%91%E6%8E%92%E5%BA%8F&action=edit&redlink=1)（smooth sort）— O(*n* log *n*)
- [快速排序](https://zh.wikipedia.org/wiki/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F)（quick sort）—O(*n* log *n*)期望时间，O(*n*2)最坏情况；对于大的、随机数列表一般相信是最快的已知排序
- [内省排序](https://zh.wikipedia.org/wiki/%E5%86%85%E7%9C%81%E6%8E%92%E5%BA%8F)（introsort）—O(*n* log *n*)
- [耐心排序](https://zh.wikipedia.org/wiki/%E8%80%90%E5%BF%83%E6%8E%92%E5%BA%8F)（patience sort）—O(*n* log *n* + *k*)最坏情况时间，需要额外的O(*n* + *k*)空间，也需要找到[最长的递增子序列](https://zh.wikipedia.org/w/index.php?title=%E6%9C%80%E9%95%B7%E7%9A%84%E9%81%9E%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97&action=edit&redlink=1)（longest increasing subsequence）

### 不实用的排序

- [Bogo排序](https://zh.wikipedia.org/wiki/Bogo%E6%8E%92%E5%BA%8F)— O(*n* × *n*!)，最坏的情况下期望时间为无穷。
- [Stupid排序](https://zh.wikipedia.org/w/index.php?title=Stupid%E6%8E%92%E5%BA%8F&action=edit&redlink=1)—O(*n*3);递归版本需要O(*n*2)额外存储器
- [珠排序](https://zh.wikipedia.org/wiki/%E7%8F%A0%E6%8E%92%E5%BA%8F)（bead sort）— O(*n*) or O(√*n*),但需要特别的硬件
- [煎饼排序](https://zh.wikipedia.org/w/index.php?title=%E7%85%8E%E9%A4%85%E6%8E%92%E5%BA%8F&action=edit&redlink=1)—O(*n*),但需要特别的硬件
- [臭皮匠排序](https://zh.wikipedia.org/wiki/%E8%87%AD%E7%9A%AE%E5%8C%A0%E6%8E%92%E5%BA%8F)（stooge sort）算法简单，但需要约n^2.7的时间

## EXAMPLE

### BUBBLE

```
do
	swapped = false
	for i = 1 to indexofLastUnsortedElement
		if leftElement > rightELement
			swap(leftElement, rightElement)
			swapped = true
while swapped
```

### INSERT

**插入排序**（英语：Insertion Sort）是一种简单直观的[排序算法](https://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。**插入排序**在实现上，通常采用in-place排序（即只需用到O(1)的额外空间的排序），因而在从后向前扫描过程中，需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间

```
mark first element as sorted
for each unsorted element
	'extract' the element
	for i = lashSortedIndex to 0
		if currentSortedElement > extracted Element
			move sorted element to the right by 1
		else insert extracted element
```
```c++
template<typename T> //整數或浮點數皆可使用,若要使用物件(class)時必須設定大於(>)的運算子功能
 2 void insertion_sort(T arr[], int len) {
 3 	int i, j;
 4 	T temp;
 5 	for (i = 1; i < len; i++) {
 6 		temp = arr[i];
 7 		j = i - 1; // 如果将赋值放到下一行的for循环内, 会导致在第10行出现j未声明的错误
 8 		for (; j >= 0 && arr[j] > temp; j--)
 9 			arr[j + 1] = arr[j];//最后一次执行该语句后，跳出当前for循环前，会再一次执行j--
10 		arr[j + 1] = temp;//执行完上一个语句（即for语句）后，跳出的位置保存在j中，此时arr[j]的值是没有经过移动的，不能替换，应该替换的是arr[j+1]
11 	}
12 }
```

### COUNT

**计数排序（Counting sort）**是一种稳定的[线性时间排序算法](https://zh.wikipedia.org/w/index.php?title=%E7%BA%BF%E6%80%A7%E6%97%B6%E9%97%B4%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95&action=edit&redlink=1)。计数排序使用一个额外的数组C，其中第i个元素是待排序数组A中值等于i的元素的个数。然后根据数组C来将A中的元素排到正确的位置。

```
create key (counting) array
for each element in list
  increase the respective counter by 1
for each counter, starting from smallest key
  while counter is non-zero
    restore element to list
    decrease counter by 1
```

### MERGE

1. 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
2. 设定两个指针，最初位置分别为两个已经排序序列的起始位置
3. 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
4. 重复步骤3直到某一指针到达序列尾
5. 将另一序列剩下的所有元素直接复制到合并序列尾

```
split each element into partitions of size 1
recursively merge adjancent partitions
  for i = leftPartStartIndex to rightPartLastIndex inclusive
    if leftPartHeadValue <= rightPartHeadValue
      copy leftPartHeadValue
    else: copy rightPartHeadValue
copy elements back to original array
```

```c++
template<typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end) {
	if (start >= end)
		return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	merge_sort_recursive(arr, reg, start1, end1);
	merge_sort_recursive(arr, reg, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2)
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	while (start1 <= end1)
		reg[k++] = arr[start1++];
	while (start2 <= end2)
		reg[k++] = arr[start2++];
	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}
template<typename T> //整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
void merge_sort(T arr[], const int len) {
	T reg[len];
	merge_sort_recursive(arr, reg, 0, len - 1);
}
```

### RADIX

**基数排序**（英语：Radix sort）是一种非比较型[整数](https://zh.wikipedia.org/wiki/%E6%95%B4%E6%95%B0)[排序算法](https://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)，其原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。由于整数也可以表达字符串（比如名字或日期）和特定格式的浮点数，所以基数排序也不是只能使用于整数。

```
create 10 buckets (queues) for each digit (0 to 9)
for each digit placing
  for each element in list
    move element into respective bucket
  for each bucket, starting from smallest digit
    while bucket is non-empty
      restore element to list
```

### SELECT

**选择排序**（Selection sort）是一种简单直观的[排序算法](https://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)。它的工作原理如下。首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。

```
repeat (numberOfElements - 1) times
	set the first unsorted as minium
	for eash of the unsorted elements
		if elements < currentMinimun
			set element as new minium
	swap minium with first unsorted position
```

### SHELL

**希尔排序**，也称**递减增量排序算法**，是[插入排序](https://zh.wikipedia.org/wiki/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F)的一种更高效的改进版本。希尔排序是非稳定排序算法。

希尔排序是基于插入排序的以下两点性质而提出改进方法的：

- 插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到[线性排序](https://zh.wikipedia.org/w/index.php?title=%E7%BA%BF%E6%80%A7%E6%8E%92%E5%BA%8F&action=edit&redlink=1)的效率
- 但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位

```
input: an array a of length n with array elements numbered 0 to n − 1
inc ← round(n/2)
while inc > 0 do:    
    for i = inc .. n − 1 do:        
        temp ← a[i]        
        j ← i        
        while j ≥ inc and a[j − inc] > temp do:            
            a[j] ← a[j − inc]            
            j ← j − inc        
        a[j] ← temp    
    inc ← round(inc / 2)
```

```c++
template<typename T> //可以使用整数或浮点数作为元素，如果使用类(class)作为元素则需要重载大于(>)运算符。
void shell_sort(T arr[], int len) {
	int gap, i, j;
	T temp;
	for (gap = len >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < len; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = temp;
		}
}
```

### QUICK

**快速排序**（英语：Quicksort），又称**划分交换排序**（partition-exchange sort），一种[排序算法](https://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)，最早由[东尼·霍尔](https://zh.wikipedia.org/wiki/%E6%9D%B1%E5%B0%BC%C2%B7%E9%9C%8D%E7%88%BE)提出。在平均状况下，排序*n*个项目要[**Ο**](https://zh.wikipedia.org/wiki/%E5%A4%A7O%E7%AC%A6%E5%8F%B7)(*n* log *n*)次比较。在最坏状况下则需要**Ο**(*n*2)次比较，但这种状况并不常见。事实上，快速排序通常明显比其他**Ο**(*n* log *n*)算法更快，因为它的内部循环（inner loop）可以在大部分的架构上很有效率地被实现出来。

```
for each (unsorted) partition
  set first element as pivot
  storeIndex = pivotIndex + 1
  for i = pivotIndex + 1 to rightmostIndex
    if element[i] < element[pivot]
      swap(i, storeIndex); storeIndex++
  swap(pivot, storeIndex - 1)
```



```c++
void quick_sort(int arr[], int left, int right) {
 int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2]; 
  /* partition */
  while (i <= j) {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) {
              tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
        }
  };
  /* recursion */
  if (left < j)
        quick_sort(arr, left, j);
  if (i < right)
        quick_sort(arr, i, right);
}
```


### R-QUICK

```
for each (unsorted) partition
  randomly select pivot, swap with first element
  storeIndex = pivotIndex + 1
  for i = pivotIndex + 1 to rightmostIndex
    if element[i] < element[pivot]
      swap(i, storeIndex); storeIndex++
  swap(pivot, storeIndex - 1)
```

常用的排序[算法](http://lib.csdn.net/base/datastructure)的时间复杂度和空间复杂度

| 排序法   | 最差时间分析     | 平均时间复杂度    | 稳定度  | 空间复杂度         |
| ----- | ---------- | ---------- | ---- | ------------- |
| 冒泡排序  | O(n2)      | O(n2)      | 稳定   | O(1)          |
| 快速排序  | O(n2)      | O(n*log2n) | 不稳定  | O(log2n)~O(n) |
| 选择排序  | O(n2)      | O(n2)      | 稳定   | O(1)          |
| 二叉树排序 | O(n2)      | O(n*log2n) | 不一顶  | O(n)          |
| 插入排序  | O(n2)      | O(n2)      | 稳定   | O(1)          |
| 堆排序   | O(n*log2n) | O(n*log2n) | 不稳定  | O(1)          |
| 希尔排序  | O          | O          | 不稳定  | O(1)          |

## Reference

