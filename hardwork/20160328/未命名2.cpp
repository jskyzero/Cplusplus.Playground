
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
    while (1) {
      int n = a.find(b);
      if (n != string::npos) {
        int n1 = n + b.length();
        a = a.erase(n, n1);
        cout << a << endl;
        int n2 = n + c.length();
        a = a.insert(n, c);
        cout << a << endl;

      } else
        break;
    }
    cout << a << endl;
  }
  return 0;
}
