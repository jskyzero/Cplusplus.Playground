/*

常量表示式对编译器来说是最优化的机会，编译器时常在编译期运行它们并且将值存入程序中。
C++11引进关键字constexpr允许用户保证函数或是对象构造函数是编译期常量。

用constexpr修饰函数将限制函数的行为。
首先，该函数的回返值类型不能为void。
第二，函数的内容必须依照"returnexpr"的形式。
第三，在参数替换后，expr必须是个常量表示式。这些常量表示式
  只能够调用其他被定义为constexpr的函数，或是其他常量表示式的数据参数。
最后，有着这样修饰符的函数直到在该编译单元内被定义之前是不能够被调用的。

*/

#include <iostream>

constexpr int getConstLength() { return 5; }

int main() {
  int a[getConstLength() + 5];
  static_assert(sizeof(a) == (sizeof(int) * 10), "size equal");
}