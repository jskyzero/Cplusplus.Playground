#include <iostream>


void select_sort(int data_size) {
  int data[data_size];
  for (int i = 0; i < data_size; i++) {
    std::cin >> data[i];
  }
  // for (int i = 0; i < data_size; i++) {
  //   std::cout << data[i];
  // }
  std::cout << (data_size) * (data_size - 1) / 2 << std::endl; 
}

int main() {
  int data_size;
  while(std::cin >> data_size) {
    select_sort(data_size);
  }  
}