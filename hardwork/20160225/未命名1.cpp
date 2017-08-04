#include <iostream>

int main() {
  using namespace std;
  float a[5] = {1.2, 1.3, 1.4, 1.5, 1.6};
  for (float x : a) cout << x << endl;
  return 0;
}
