#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  string str2;
  char ch;
  getline(cin, str);
  str2 = str;

  ch = str[0];
  if (ch >= 'a' && ch <= 'z') {
    ch -= 32;
    str[0] = ch;
  }

  int n = str2.find(" ");
  int N = 0;
  while (n != string::npos) {
    N += n;

    ch = str[N + 1];
    if (ch >= 'a' && ch <= 'z') {
      ch -= 32;
      str[0] = ch;
    }
    str2.erase(0, n + 1);
    n = str2.find(" ");
  }

  cout << str << endl;
  return 0;
}
