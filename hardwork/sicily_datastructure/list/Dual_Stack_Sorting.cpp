#include <iostream>  // for cin cout
#include <stack>     // for stack
#include <vector>    // for vector
#include <sstream>

typedef std::stack<int> Stack;
typedef std::vector<int> Vector;

class DualStackSort {
 public:
  DualStackSort();
  void initial();
  friend std::istream &operator>>(std::istream &input, DualStackSort &my_sort);
  friend std::ostream &operator<<(std::ostream &output, DualStackSort &my_sort);
  void sort();
  bool isOk();

 private:
  Vector in;
  Vector out;
  std::stringstream ss;
};

DualStackSort::DualStackSort() { initial(); }

void DualStackSort::initial() {
  in.clear();
  out.clear();
  ss = std::stringstream();
}

void DualStackSort::sort() {
  for (auto &num : in) {
    if(ss.str().empty()) ss << " "; 
    ss << num;
  }
}

bool DualStackSort::isOk() { return 1; }

std::istream &operator>>(std::istream &input, DualStackSort &my_sort) {
  my_sort.initial();

  int in_size, temp_num;
  input >> in_size;
  for (int i = 0; i < in_size; i++) {
    input >> temp_num;
    my_sort.in.push_back(temp_num);
  }
  return input;
}

std::ostream &operator<<(std::ostream &output, DualStackSort &my_sort) {
  my_sort.sort(); 
  output << my_sort.ss.str();
  return output;
}

int main() {
  DualStackSort my_sort;
  while (std::cin >> my_sort) std::cout << my_sort << std::endl;
}