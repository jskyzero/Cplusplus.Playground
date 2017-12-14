#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>

typedef std::map<int, int> Map;

void cal_num(int size) {
  int temp_num;
  Map data;
  for (int i = 0; i < size; i++) {
    std::cin >> temp_num;
    data[temp_num]++;
  }
  for (auto & each_data :data) {
      printf("%d %d\n",each_data.first, each_data.second);
  }
}

int main() {
  int size;
  bool first = true;
  while (std::cin >> size) {
    if (first) {
      first = false;
    } else {
      std::cout << std::endl;
    }
    cal_num(size);
  }
}