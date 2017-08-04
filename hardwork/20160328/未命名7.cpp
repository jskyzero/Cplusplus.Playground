#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, N;
  cin >> n;
  N = n;
  string str[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
  }
  cin >> str[0];

  for (int i = 1; i <= n; i++) {
    cout << str[i] << endl;
  }
  string str0 = str[0];

  int n0 = str[0].length();
  return 0;
}
