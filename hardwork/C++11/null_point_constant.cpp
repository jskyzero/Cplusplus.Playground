/*

C++11引入了新的关键字来代表空指针常量：nullptr，将空指针和整数0的概念拆开。
nullptr的类型为nullptr_t，能隐式转换为任何指针或是成员指针的类型，
也能和它们进行相等或不等的比较。而nullptr不能隐式转换为整数，也不能和整数做比较。

*/

int main() {
  char* p = nullptr;
}