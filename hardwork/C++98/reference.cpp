#include <iostream>

int& getIntReference(int** p, int n) {
  int* num = new int;
  *p = num;
  std::cout << "memory address = " << *p << std::endl;
  *num = n;
  return *num;
}

int main() {
  int a = 1;
  int& b = a;

  a = 2;
  std::cout << "a = " << a << " "
            << "&a = " << &a << std::endl
            << "b = " << b << " "
            << "&b = " << &b << std::endl
            << std::endl;

  int* p = NULL;
  a = getIntReference(&p, -1);
  std::cout << "a = " << a << " "
            << "&a = " << &a << std::endl
            << "b = " << b << " "
            << "&b = " << &b << std::endl
            << std::endl;
  std::cout << "memory address = " << p << std::endl;
  *p = 0;
  std::cout << "a = " << a << " "
            << "&a = " << &a << std::endl
            << "b = " << b << " "
            << "&b = " << &b << std::endl
            << std::endl;
  delete p;
  std::cout << "a = " << a << " "
            << "&a = " << &a << std::endl
            << "b = " << b << " "
            << "&b = " << &b << std::endl
            << std::endl;

  b = getIntReference(&p, -2);
  std::cout << "a = " << a << " "
            << "&a = " << &a << std::endl
            << "b = " << b << " "
            << "&b = " << &b << std::endl
            << std::endl;
  std::cout << "memory address = " << p << std::endl;
  *p = 0;
  std::cout << "a = " << a << " "
            << "&a = " << &a << std::endl
            << "b = " << b << " "
            << "&b = " << &b << std::endl
            << std::endl;
  delete p;
  std::cout << "a = " << a << " "
            << "&a = " << &a << std::endl
            << "b = " << b << " "
            << "&b = " << &b << std::endl
            << std::endl;
  return 0;
}