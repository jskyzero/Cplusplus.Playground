#include <algorithm>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

void deal() {
  istream_iterator<string> it(cin);
  cout << *it;
  for_each(++it, istream_iterator<string>(), [](string ss) {
    ss[0] = toupper(ss[0]);
    cout << " " << ss;
  });
}

int main() {
  deal();
  return 0;
}
/*
string str;

    char ch;
    getline(cin,str);


        ch = str[0];
    if( (ch >= 'a') && (ch <= 'z')) {
        ch -= 'a'-'A';
        str[0] = ch;

        }

        int n = str.find(" ",0);


        while(n != string::npos) {


                ch = str[n+1];
    if( (ch >= 'a') && (ch <= 'z')) {
        ch -= 32;
        str[n+1] = ch;
    }


        n = str.find(" ",n);
        }




    cout << str
                 << endl;
*/
