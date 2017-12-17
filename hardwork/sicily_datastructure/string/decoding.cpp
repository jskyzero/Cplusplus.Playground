#include <iostream>
#include <string>
#include <cstring>
#include <cctype>


using namespace std;

int main() {
  string str;
  char ch;
  int times;

  while (cin >> str && str != "XXX") {
    
    for(int i = 0; i < str.length();i++) {
      ch = str[i];
      times = 0;
      while ( i + 1 < str.length() && isdigit(str[i+1])) {
        times = times * 10 + str[i+1] - '0';
        i++;
      }
      if (!times) {
        cout << ch;
      } else {
        for (int i = 0; i < times; i++) {
          cout << ch;
        }
      } 
    }
    cout << endl;
  }
}