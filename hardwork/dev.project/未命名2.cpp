#include <iostream>
using namespace std;

int addxy(int x, int y, int total) {
  total = x + y;
  cout << "Total from inside addxy: " << total << endl;
  return total;
}
int subxy(int x, int y, int& p) {
  p = x - y;
  cout << "Total from inside subxy: " << p << endl;
  return p;
}
void printtotal(int total) { printf("Total in Main: %d\n", total); }

int main() {
  int x, y, total;

  x = 10;

  y = 5;

  total = 0;

  printtotal(total);

  addxy(x, y, total);

  printtotal(total);

  subxy(x, y, total);

  printtotal(total);

  return 0;
}
