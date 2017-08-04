#include <stdio.h>
long f(char* ptr, int n) {
  if (ptr[n + 1] == '\0') return 1;
  if (ptr[n] == '2' && ptr[n + 1] <= '6')
    return (f(ptr, n + 1) + f(ptr, n + 2));
  else if (ptr[n] == '1')
    return (f(ptr, n + 1) + f(ptr, n + 2));
  else if (ptr[n] == '\0')
    return 1;
  else
    return f(ptr, n + 1);
}
int main() {
  char string[100] = {'\0'};
  int n = 0;
  while (scanf("%s", string), string[0] != '0') {
    printf("\n%s\n", string);
    n = 0;
    printf("%ld\n", f(string, n));
  }
  return 0;
}
