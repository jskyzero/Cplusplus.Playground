#include <cstdio>
#include <algorithm>
#include <vector>

#define ARRAY_LENGTH 250000

void print_vector(std::vector<int> v) {
    for(auto num : v) {
        printf("%d ", num);
    }
    printf("\n");
}

int num[ARRAY_LENGTH];
int main() {
  std::vector<int> v = {1, 5 ,15 ,890, 23};
  print_vector(v);
  v.push_back(2);
  print_vector(v);
  v.pop_back();
  print_vector(v);
  std::make_heap(v.begin(), v.end());
  print_vector(v);
  std::pop_heap(v.begin(), v.end());
  print_vector(v);
  v.pop_back();
  print_vector(v);
  v.push_back(23);
  std::push_heap(v.begin(), v.end());
  print_vector(v);
  std::sort_heap(v.begin(), v.end());
  print_vector(v);

  // int num_size, i, temp_num;
  // scanf("%d", &num_size);
  // for (i = 0; i < num_size / 2 + 1; i++) {
  //     scanf("%d", &num[i]);
  // }

  // for (i; i < num_size; i++) {
  //     scanf("d", &temp_num);

  // }
}