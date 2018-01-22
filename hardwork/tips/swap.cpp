// reference
// 【证明】加减法交换两个整数，过程可能会溢出，但结果依然正确
// http://blog.csdn.net/friendbkf/article/details/50311441

#include <cstdio>
#include <climits>
#include <cassert>


int main() {
  int a = INT_MAX - 1;
  int b = INT_MAX - 2;

  a = a + b;
  b = a - b;
  a = a - b;

  assert(a == INT_MAX - 2);
  assert(b == INT_MAX - 1);

}