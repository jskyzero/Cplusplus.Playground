/*

[](int x, int y) -> int { int z = x + y; return z + x; }

[]      // 沒有定义任何变量。使用未定义变量会引发错误。
[x, &y] // x以传值方式传入（默认），y以引用方式传入。
[&]     // 任何被使用到的外部变量都隐式地以引用方式加以引用。
[=]     // 任何被使用到的外部变量都隐式地以传值方式加以引用。
[&, x]  // x显式地以传值方式加以引用。其余变量以引用方式加以引用。
[=, &z] // z显式地以引用方式加以引用。其余变量以传值方式加以引用。

*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

int main() {
  std::vector<int> v {1, 2, 3, 4, 5};
  int total = 0;

  // you can use auto
  std::function<void(int)> lambdaFunc = [&total](int x) {
    total += x;
  };

  std::for_each(v.begin(), v.end(), lambdaFunc);

  std::cout << total;
}