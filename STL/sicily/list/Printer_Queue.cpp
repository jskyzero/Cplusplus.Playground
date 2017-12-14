//
// jskyzero
//

#include <iostream>
#include <queue>
#include <cstring>

#define MAX_WEIGHT 10

typedef std::queue<int> Queue;

void print_queue(Queue initial_queue) {
  Queue copied_queue = initial_queue;
  while (!copied_queue.empty()) {
    std::cout << copied_queue.front() << "-";
    copied_queue.pop();
  }
  std::cout << "end\n";
}

int find_max_in_queue(Queue initial_queue) {
  Queue copied_queue = initial_queue;
  int max_num = initial_queue.front();
  while (!copied_queue.empty()) {
    max_num = copied_queue.front() > max_num ? copied_queue.front() : max_num;
    copied_queue.pop();
  }
  return max_num;
}

class PrinterQueue {
 public:
  PrinterQueue();
  int simulation_wait();
  friend std::ostream &operator<<(std::ostream &output, PrinterQueue &my_printer_queue);
  friend std::istream &operator>>(std::istream &input, PrinterQueue &my_printer_queue);

 private:
  typedef std::queue<int> Queue;
  int my_index;
  int my_weight;
  Queue wait_queue;
};

PrinterQueue::PrinterQueue() {}

int PrinterQueue::simulation_wait() {
  int wait_times = 0;
  for (int select_wight = MAX_WEIGHT - 1; select_wight >= my_weight ; select_wight--) {

    while(select_wight == find_max_in_queue(wait_queue)) {
      if(wait_queue.front() == select_wight) {
        wait_times++;
        if(my_index == 0) break;
        else {
          wait_queue.pop();
          my_index--;
        }
      } else {
        my_index--;
        wait_queue.push(wait_queue.front());
        wait_queue.pop();
        if(my_index < 0) {
          my_index+= wait_queue.size();
        }
      }
      // print_queue(wait_queue);
    }
  }
  return wait_times;
}

std::ostream &operator<<(std::ostream &output, PrinterQueue &my_printer_queue) {
  // output << my_printer_queue.my_weight << ' ' << my_printer_queue.my_index << std::endl;
  // while (!my_printer_queue.wait_queue.empty()) {
  //   output << my_printer_queue.wait_queue.front() << " ";
  //   my_printer_queue.wait_queue.pop();
  // }
  output << my_printer_queue.simulation_wait();
  return output;
}

std::istream &operator>>(std::istream &input, PrinterQueue &my_printer_queue) {
  int queue_size, my_index, temp_weight;

  input >> queue_size >> my_index;
  my_printer_queue.my_index = my_index;

  for(int index = 0; index < queue_size; index++) {
    input >> temp_weight;
    if(index == my_index) my_printer_queue.my_weight = temp_weight;
    my_printer_queue.wait_queue.push(temp_weight);
  }
  return input;
}

int main() {
  int num;  // at most 100
  std::cin >> num;
  while (num--) {
    PrinterQueue my_printer_queue;
    std::cin >> my_printer_queue;
    std::cout << my_printer_queue << std::endl;
  }
}