#include <iostream>
#include <list>
#include <algorithm>

typedef std::list<int> List;

void card_game();

int main () {
  int times; 
  std::cin >> times;
  while (times--) {
    card_game();
  }
}

void card_game() {
  int size;
  std::cin >> size;
  List card_queue;
  for (int i = 0; i < size; i++ ) {
    card_queue.push_back(i+1);
  }
  while (card_queue.size() >= 2) {
    std::cout << card_queue.front() << ' ';
    card_queue.pop_front();
    card_queue.push_back(card_queue.front());
    card_queue.pop_front();
  }
  for (auto & id : card_queue) {
    std::cout << id << ' ';
  }
  std::cout << std::endl;
}