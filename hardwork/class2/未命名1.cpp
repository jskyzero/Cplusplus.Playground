#include <iostream>
#include <string>

using namespace std;

class date {
 public:
  int a;
  int b;
  date(int a = 0, int b = 0) {
    this->a = a;
    this->b = b;
  }
  date operator+(date& p) {
    this->a += p.a;
    this->b += p.b;
    return *this;
  }
};
int main() {
  date a(1, 1);
  date b(2, 2);
  date c = a + b;
  cout << c.a;
}
