#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int d[1020];
int flag = 0;

int main() {
  int n;
  string a;
  string b[1020];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  cin >> a;
  int len = a.length();
  for (int i = 0; i < len; i++) {
    int ok = 0;
    for (int t = len - i; t >= 0; t--) {
      string d = a.substr(i, t);
      for (int k = 0; k < n; k++) {
        if (d == b[k]) {
          if (flag)
            cout << " " << b[k];
          else
            cout << b[k];
          i = i + t - 1;
          ok = 1;
          flag = 1;
        }
      }
    }
    if (!ok) {
      if (flag)
        cout << " " << a[i];
      else
        cout << a[i];
      flag = 1;
    }
  }
  cout << "0";
  cout << endl;
}
