#include <iostream>
#include <list>
#include <algorithm>
#include <ciso646>
typedef std::list<int> List;


void rails(int size) {
  List rail_list, in, rail_stack, out;
  bool success;
  for (int i = 0; i < size; i++) {
    rail_list.push_back(i+1);
  }

  int first;
  std::cin >> first;
  while (first) {
    success = 1;
    in = rail_list;
    out.clear();
    rail_stack.clear();
    out.push_back(first);

    for (int i = 1; i < size; i++) {
      std::cin >> first;
      out.push_back(first);
    }

    for(auto & num : out) {
      // std::cout << num << ' ';
      if (not rail_stack.empty() and rail_stack.front() == num) {
        rail_stack.pop_front();
        continue;
      }
      while (not in.empty() and in.front() < num) {
        rail_stack.push_front(in.front());
        in.pop_front();
      }
      if (not in.empty() and in.front() == num) {
        in.pop_front();
        continue;
      }
      success = 0;
    }
    std::cout << (success ? "Yes\n" : "No\n");
    std::cin >> first;
  }
  std::cout << std::endl; 
} 

int main() {
  int size;
  std::cin >> size;
  while (size) {
    rails(size);
    std::cin >> size;
  }
}