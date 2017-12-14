#include <cstdio>
#include <algorithm>

#define ARRAY_LENGTH 250001

void print_num(int * num) {
    for (int i = 0; i < sizeof(num); i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
int num[ARRAY_LENGTH];
int main() {
  int num_size, actually_size, i, temp_num;
  float ans;

  scanf("%d", &num_size);
  actually_size = num_size / 2 + 1;

  for (i = 0; i < actually_size; i++) {
    scanf("%d", &num[i]);
  }
  std::make_heap(num, num + actually_size);


  for (i; i < num_size; i++) {
    scanf("%d", &temp_num);
    if (temp_num < num[0]) {
      std::pop_heap(num, num + actually_size);
      num[actually_size - 1] = temp_num;
      std::push_heap(num, num + actually_size);
    }
  }

  if (1 == num_size % 2)
    ans = (float)num[0];
  else {
    std::pop_heap(num, num + actually_size);
    ans = ((float)num[0] + std::max(num[1], num[2])) / 2;
  }
  printf("%.1f", ans);
}