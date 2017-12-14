#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
struct data {
  int a;
  int b;
  int c;
  int all;
  int num;
};
int cmp1(data a, data b) { return a.all < b.all; }
void _swap(data *a, data *b) {
  data tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
void com(data *a, data *b) {
  if ((*a).a < (*b).a)
    _swap(a, b);
  else if ((*a).a > (*b).a)
    return;
  else {
    if ((*a).num < (*b).num)
      return;
    else
      _swap(a, b);
  }
}
int main() {
  int N;
  int flag = 1;
  while (scanf("%d", &N) != EOF) {
    data tmp[N + 1];
    for (int n = 1; n <= N; n++) {
      scanf("%d%d%d", &tmp[n].a, &tmp[n].b, &tmp[n].c);
      tmp[n].all = tmp[n].a + tmp[n].b + tmp[n].c;
      tmp[n].num = n;
    }
    sort(tmp + 1, tmp + N + 1, cmp1);
    if (flag == 0)
      printf("\n");
    else
      flag = 0;
    for (int n = N, m = 5; m > 0; m--, n--) {
      int i = n - 1;
      while (tmp[n].all == tmp[i].all) {
        com(&tmp[n], &tmp[i]);
        i--;
      }
      printf("%d %d\n", tmp[n].num, tmp[n].all);
    }
  }
  return 0;
}