#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <ciso646>

typedef std::list<int> List;
typedef std::set<int> Set;
int isOK(List &student_list) {
  return Set(student_list.begin(), student_list.end()).size() == 1
             ? student_list.front()
             : 0;
}

void change(List &student_list) {
  auto change_list = student_list;
  for (auto &num : change_list) {
    num /= 2;
  }
  change_list.push_back(change_list.front());
  change_list.pop_front();
  auto student_it = student_list.begin();
  auto add_it = change_list.begin();
  for (; student_it != student_list.end(); student_it++, add_it++) {
    *student_it = *student_it / 2 + *add_it;
    *student_it = *student_it%2 == 0 ? *student_it: *student_it + 1;
  }
}

void candy(int size) {
  int pieces_num, times = 0;
  List student_list;
  for (int i = 0; i < size; i++) {
    std::cin >> pieces_num;
    student_list.push_back(pieces_num);
  }

  while (not isOK(student_list)) {
    change(student_list);
    times++;
    // for (auto &num : student_list) {
    //   std::cout << num << " ";
    // }
    // std::cout << std::endl;
  }
  std::cout << times << " " << isOK(student_list) << std::endl;
}

int main() {
  int size;
  while (std::cin >> size and size) {
    candy(size);
  }
}