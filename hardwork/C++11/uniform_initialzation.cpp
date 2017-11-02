/*

如果一个类别拥有初始化列表构造函数（TypeName(initializer_list<SomeType>);），
而初始化列表与构造函数的参数类型一致，那么它比其他形式的构造函数的优先权都来的高。

*/

int main() {
  int n0 = int(1);
  int n1 = 1;
  int n2[] = {1, 2};
  // use constructor
  int *p = new int[3]{1, 2, 3};
  delete p;
}