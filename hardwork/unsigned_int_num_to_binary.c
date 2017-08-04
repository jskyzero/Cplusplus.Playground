#include <stdio.h> // for printf(), putchar()

void display(unsigned value);

int main() {
  unsigned x;
  x = 1;
  while (x) {
    printf("please Enter an unsigned integer value ");
    scanf("%u", &x);
    display(x);
  }
  return 0;
}

void display(unsigned value) {
  unsigned c;
  // this means just produce the 1000 0000 0000 000
  unsigned displayMask = 1 << 31;

  printf("%10u = ", value);

  for (c = 1; c <= 32; c++) {
    // each print one char
    putchar(value & displayMask ? '1' : '0');
    // left move to next char
    value <<= 1;
    // format
    if (c % 8 == 0) putchar(' ');
  }
  putchar('\n');
}
