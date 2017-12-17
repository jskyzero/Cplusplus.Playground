#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <ciso646>

typedef struct {
  int left;
  int right;
} Couple;

typedef std::list<Couple> List;
typedef std::stack<int> Stack;

class Couples{
public:
  Couples(){};
  // void initial(int couples_size);
  void solve();
  friend std::istream &operator>>(std::istream &input, Couples &couples);
  friend std::ostream &operator<<(std::ostream &output, Couples &couples);
private:
  Stack couples_stack;
  List couples_list;
  int couples_size;
};

// void Couples::initial(int couples_size) {
//   for (int index = 0; index < 2 * couples_size; index++) {
//     couples_stack.push(index+1);
//   }
// }

void Couples::solve() {
    for (int index = 0; index < 2 * couples_size; index++) {
      bool removed = false;
      for (auto & couples: couples_list) {
        if((not couples_stack.empty() and couples_stack.top() == couples.left) 
            and index+1 == couples.right) {
              removed = true;
              couples_stack.pop();
            }
      }
    if (not removed) couples_stack.push(index+1);
  }
}

std::istream &operator>>(std::istream &input, Couples &couples) {
  int couples_size, left, right;
  input >> couples_size;
  couples.couples_size = couples_size;

  while (couples_size--) {
    input >> left >> right;
    left = std::min(left, right);
    right =  std::max(left, right);
    Couple temp_couple = {left, right};
    couples.couples_list.push_back(temp_couple);
  }

  return input;
}

std::ostream &operator<<(std::ostream &output, Couples &couples) {
  couples.solve();
  output << (couples.couples_stack.empty() ? "Yes" :"No"); 
  return output;
}

int main() {
  int times;
  std::cin >> times;
  while(times--) {
    Couples couples;
    std::cin >> couples;
    std::cout << couples << std::endl;
  }
} 