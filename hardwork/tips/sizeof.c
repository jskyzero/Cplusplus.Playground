/*

this code can be compiled both in C and C++

I just want to test the sizeof :)

*/
#include <stdio.h>

int main() {
  int a[10];
  int* p = a;
  printf("int a[10];\n");
  printf("int* p = a;\n");
  printf("sizeof(a) = %lu\n", sizeof(a));
  printf("sizeof(p) = %lu\n", sizeof(p));
  printf("sizeof(&a) = %lu\n", sizeof(&a));
  printf("sizeof(&a[0]) = %lu\n", sizeof(&a[0]));

  return 0;
}
