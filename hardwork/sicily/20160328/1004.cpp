
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int N = 0;
  cin >> N;

  while (N--) {
    string a, b, c;
    cin >> a >> b >> c;
    int n = 0;
    while (1) {
      n = a.find(b);
      if (n != string::npos) {
        a.erase(n, b.length());

        a.insert(n, c);

      } else
        break;
    }
    cout << a << endl;
  }
  return 0;
}
