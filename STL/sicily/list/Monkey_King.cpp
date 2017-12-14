#include <iostream>
#include <vector>
#include <algorithm>
#include <ciso646>
#include <typeinfo>

typedef std::vector<int> Vector;


void select() {
  int size, king_id, pos = 0;
  Vector monkey;
  std::cin >> size >> king_id;

  for (int id = 0; id < size; id++) {
    monkey.push_back(id+1);
  }
  while(monkey.size() > 1) {
    int pos0 = pos;
    pos = ((king_id  %  (int)monkey.size()) + pos0 - 1) %  (int)monkey.size();
    auto a = (king_id  %  monkey.size()) + pos0 - 1;
    int ans = (king_id + pos0 - 1) %  monkey.size();
   
    if (ans != pos) {
      int check = -1 % monkey.size();
      std::cout << check
                // << " size " << typeid(monkey.size()).name()
                // << " left " << typeid((king_id  %  monkey.size()) + pos - 1).name()
                // << " int " << typeid((int)(king_id  %  monkey.size()) + pos - 1).name()
                // << (((int)(king_id  %  monkey.size()) + pos - 1)) << " " << monkey.size()
                // << " pos " << typeid(pos).name() << pos
                // << " ans " << ans
                << "   ";
    }
    monkey.erase(find(monkey.begin(), monkey.end(), monkey[pos]));
  }
  std::cout << monkey[0] << std::endl;
}

int main() {
  int times;
  std::cin >> times;
  while(times--) {
    select();
  }
}