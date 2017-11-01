#include<iostream>
using namespace std;

class Int;
ostream & operator<<(ostream& os, Int & temp);
istream & operator>>(istream& os, Int & temp);

class Int
{
  
public:
  int i;
  Int(int n = 0){this->i = n;}
  int getI() { return i;}
  //add any member function needed here
  friend ostream & operator<<(ostream& os, Int & temp);
  friend istream & operator>>(istream& os, Int & temp);
  friend Int operator+(Int  left, Int  right);
  friend Int operator-(Int  left, Int  right);
  friend Int operator+=(Int & left, Int  right);
  friend Int operator-=(Int & left, Int  right);
  friend Int operator*(Int  left, Int  right);
  friend Int operator/(Int  left, Int  right);
  friend Int operator%(Int  left, Int  right);
  Int & operator++() {this->i++; return * this;}
  Int & operator--() {this->i--; return * this;}
  Int  operator++(int) {Int temp(this->getI()); this->i++; return temp;}
  Int  operator--(int) {Int temp(this->getI()); this->i--; return temp;}
  operator int();

};
ostream & operator<<(ostream& os,Int & temp){os << temp.getI(); return os;}
istream & operator>>(istream& os, Int & temp){ int n;os >> n; temp.i = n; return os;}
Int operator+(Int  left, Int  right) {Int temp(left.getI()+right.getI());return temp;}
Int operator-(Int  left, Int  right) {Int temp(left.getI()-right.getI());return temp;}

Int operator+=(Int & left, Int  right) {Int temp(left.getI()+right.getI());left.i = temp.getI();return temp;} 
Int operator-=(Int & left, Int  right) {Int temp(left.getI()-right.getI());left.i = temp.getI();return temp;} 
Int operator*(Int  left, Int  right) {Int temp(left.getI()*right.getI());return temp;}
Int operator/(Int  left, Int  right) {Int temp(left.getI()/right.getI());return temp;}
Int operator%(Int  left, Int  right) {Int temp(left.getI()%right.getI());return temp;}

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
  cout <<  c+d << endl;
  cout <<  1+c << endl;
  cout <<  c+1 << endl;
  cout <<  1.5+c << endl;
  cout <<  c+1.5 << endl;

  cout <<  a + b + c + d << endl;

  d -= 1;
  d -= 1.5;
  cout <<  c-d << endl;
  cout <<  1-c << endl;
  cout <<  c-1 << endl;
  cout <<  1.5-c << endl;
  cout <<  c-1.5 << endl;

  d *= 1;
  d *= 1.5;
  cout <<  c*d << endl;
  cout <<  9*c << endl;
  cout <<  c*9 << endl;
  cout <<  19.4*c << endl;
  cout <<  c*19.4 << endl;
  d /= 2;
  d /= 2.5;
  cout <<  d/c << endl;
  cout <<  2/c << endl;
  cout <<  c/2 << endl;
  cout <<  2.5/c << endl;
  cout <<  c/2.5 << endl;

  cout <<  b%c << endl;
  cout <<  5%c << endl;
  cout <<  c%2 << endl;

  cout <<  c++ << endl;
  cout <<  ++c << endl;
  cout <<  c-- << endl;
  cout <<  --c << endl;    
  cout <<  -c << endl;
  
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
