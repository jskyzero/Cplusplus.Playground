#include <iostream>
#include <list>
#include <algorithm>

typedef std::list<int> List;

class MoveBall {
 public:
  MoveBall(){};
  void initial(int balls_size);
  void exec(int exec_code, int ball_x, int ball_y);
  friend std::istream &operator>>(std::istream &input, MoveBall &my_obj);
  friend std::ostream &operator<<(std::ostream &output, MoveBall &mu_obj);

 private:
  List ball_list;
};

void MoveBall::initial(int balls_size) {
  for (int ball_num = 0; ball_num < balls_size; ball_num++) {
    ball_list.push_back(ball_num + 1);
  }
}

void MoveBall::exec(int exec_code, int ball_x, int ball_y) {
  auto ball_x_it =
      std::find_if(std::begin(ball_list), std::end(ball_list),
                   [&](const int ball_num) { return ball_num == ball_x; });
  ball_list.erase(ball_x_it);
  auto ball_y_it =
      std::find_if(std::begin(ball_list), std::end(ball_list),
                   [&](const int ball_num) { return ball_num == ball_y; });
  ball_y_it = (exec_code - 1) ? ++ball_y_it : ball_y_it;
  ball_list.insert(ball_y_it, ball_x);
}

std::istream &operator>>(std::istream &input, MoveBall &my_obj) {
  int balls_size, times, ball_x, ball_y, exec_code;
  input >> balls_size >> times;
  my_obj.initial(balls_size);
  while (times--) {
    input >> exec_code >> ball_x >> ball_y;
    my_obj.exec(exec_code, ball_x, ball_y);
  }
  return input;
}

std::ostream &operator<<(std::ostream &output, MoveBall &my_obj) {
  for (auto &ball_num : my_obj.ball_list) {
    output << ball_num << " ";
  }
  output << std::endl;
  return output;
}

int main() {
  int times;
  std::cin >> times;
  while (times--) {
    MoveBall my_obj;
    std::cin >> my_obj;
    std::cout << my_obj;
  }
}