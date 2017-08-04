#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;

  char ch;
  getline(cin, str);

  if (islower(str[0])) {
    str[0] -= 'a' - 'A';
  }
  int n2 = 0;
  int n = str.find(" ", n2);

  while (1) {
    n2 = n;

    if (islower(str[n + 1])) {
      str[n + 1] -= 'a' - 'A';
    }

    n = str.find(" ", n2 + 1);
    if (string::npos == n) break;
  }

  cout << str << endl;
}
