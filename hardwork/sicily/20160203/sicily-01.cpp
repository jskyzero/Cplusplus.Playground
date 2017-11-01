#include <stdio.h>

int f(char* p, int n) {
  printf("A%c\nB%c\n", *(p + n), *(p + n + 1));
  if (*(p + n) = '\0')
    return 1;
  else if (*(p + n) > '2' || *(p + n) == '0')
    return (f(p, n + 1));
  else if (*(p + n) == '1')
    return (f(p, n + 1) + f(p, n + 2));
  else if (*(p + n) == '2' && *(p + n + 1) <= '6')
    return (f(p, n + 1) + f(p, n + 2));
  else if (*(p + n) == '2' && *(p + n + 1) > '6')
    return (f(p, n + 1));
  else
    return 1;
}
int main() {
  char string[50];
  int index;
  int i, j, k;
  for (i = 0; i < 50; i++) {
    string[i] = '\0';
  }
  index = 0;
  scanf("%s", string);

  while (string[0] != '0') {
    printf("%s\n", string);

    printf("%d\n", f(string, index));

    for (i = 0; i < 50; i++) {
      string[i] = '\0';
    }
    index = 0;
    scanf("%s", string);
  }
  return 0;
}
