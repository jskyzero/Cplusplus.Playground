#include<iostream>
using namespace std;
#define Int int

void f()
{
   Int a=0;
  Int b(1);
  Int c(2.5);
  Int d = 99.5;

  cout <<  a << endl;
  cout <<  b << endl;
  cout <<  c << endl;
  cout <<  d << endl;
  
  d += 1;
  d += 1.5;
  cout <<  d << endl;
  cout <<  c+d << endl;
  cout <<  1+c << endl;
  cout <<  c+1 << endl;
  cout <<  1.5+c << endl;
  cout <<  c+1.5 << endl;

  cout <<  a + b + c + d << endl;

  d -= 1;
  d -= 1.5;
  cout <<  d << endl;
  cout <<  c-d << endl;
  cout <<  1-c << endl;
  cout <<  c-1 << endl;
  cout <<  1.5-c << endl;
  cout <<  c-1.5 << endl;


  
  int c1 = c;
  cout << c1 << endl;
  c1 = c;  
  cout << c1 << endl;  

  cin >> d;
  cout <<  d << endl;
}
int main()
{
	f();
}
