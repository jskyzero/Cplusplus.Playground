/*
Ret的类型由LHS与RHS相加之后的结果的类型来决定。
template< typename LHS, typename RHS> 
  Ret AddingFunc(const LHS &lhs, const RHS &rhs) {return lhs + rhs;} //Ret的型別必須是(lhs+rhs)的型別
使用C++11新加入的decltype来声明AddingFunc的回返类型，依然不可行。
  template< typename LHS, typename RHS> 
  decltype(lhs+rhs) AddingFunc(const LHS &lhs, const RHS &rhs) {return lhs + rhs;} //不合法的C++11
不合法的原因在于lhs及rhs在定义前就出现了。直到剖析器解析到函数原型的后半部，lhs与rhs才是有意义的。

针对此问题，C++11引进一种新的函数定义与声明的语法：


template< typename LHS, typename RHS> 
  auto AddingFunc(const LHS &lhs, const RHS &rhs) -> decltype(lhs+rhs) {return lhs + rhs;}

这种语法也能套用到一般的函数定义与声明，如下：

*/

#include <iostream>

class SomeStruct
{
  public:
  static constexpr auto add(int x, int y) -> int {
    return x + y;
  }
};


int main() {
  std::cout << SomeStruct::add(1, 2) << std::endl;
}