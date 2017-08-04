#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, N;
  cin >> n;

  string str[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
  }
  cin >> str[0];

  N = str[0].length();
  int flag = 0;
  for (int x = 0; x < N; x++) {
    int flag0 = 1;
    for (int y = N - x; y >= 0; y--) {
      string temp = str[0].substr(x, y);
      for (int i = 1; i <= n; i++) {
        if (temp == str[i]) {
          flag0 = 0;
          if (flag) cout << " ";
          cout << str[i];
          flag = 1;
          x = x + y - 1;
        }
      }
    }
    if (flag0) {
      if (flag) cout << " ";
      cout << str[0][x];
      flag = 1;
    }
  }
  cout << endl;
  return 0;
}
