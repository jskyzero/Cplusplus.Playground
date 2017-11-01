#include<iostream>
using namespace std;

class Int;
ostream & operator<<(ostream& os, Int & temp);
istream & operator>>(istream& os, Int & temp);

class Int
{
  int i;
public:
  
  Int(int n = 0){this->i = n;}
  int getI() { return i;}
  //add any member function needed here
  friend ostream & operator<<(ostream& os, Int & temp);
  friend istream & operator>>(istream& os, Int & temp);
  friend Int operator+(Int  left, Int  right);
  friend Int operator+(int  left, Int  right);
  friend Int operator+(Int  left, int  right);
  friend double operator+(double  left, Int  right);
  friend double operator+(Int  left, double  right);
  friend Int operator-(Int  left, Int  right);
  friend Int operator-(int  left, Int  right);
  friend Int operator-(Int  left, int  right);
  friend double operator-(double  left, Int  right);
  friend double operator-(Int  left, double  right);

  friend Int operator+=(Int & left, Int  right);
  friend Int operator-=(Int & left, Int  right);
  friend Int operator-=(Int & left, double  right);
  
  friend Int operator*(Int  left, Int  right);
  friend Int operator*(int  left, Int  right);
  friend Int operator*(Int  left, int  right);
  friend double operator*(double  left, Int  right);
  friend double operator*(Int  left, double  right);
  friend Int operator*=(Int & left, Int  right);
  friend Int operator*=(Int & left, int  right);
  friend Int operator*=(Int & left, double  right);
  
  friend Int operator/(Int  left, Int  right);
  friend Int operator/(int  left, Int  right);
  friend Int operator/(Int  left, int  right);
  friend double operator/(double  left, Int  right);
  friend double operator/(Int  left, double  right);
  friend Int operator/=(Int & left, Int  right);
  friend Int operator/=(Int & left, int  right);
  friend Int operator/=(Int & left, double  right);
  
  friend Int operator%(Int  left, Int  right);
  friend Int operator%(int  left, Int  right);
  friend Int operator%(Int  left, int  right);

  
  Int & operator++() {this->i++; return * this;}
  Int & operator--() {this->i--; return * this;}
  Int  operator++(int) {Int temp(this->getI()); this->i++; return temp;}
  Int  operator--(int) {Int temp(this->getI()); this->i--; return temp;}
  operator int(){return i;}

};
ostream & operator<<(ostream& os,Int & temp){os << temp.getI(); return os;}
istream & operator>>(istream& os, Int & temp){ int n;os >> n; temp.i = n; return os;}

Int operator+(Int  left, Int  right) {Int temp(left.getI()+right.getI());return temp;}
Int operator+(int  left, Int  right) {Int temp(left+right.getI());return temp;}
Int operator+(Int  left, int  right) {Int temp(left.getI()+right);return temp;}
double operator+(double  left, Int  right) {double temp(left+right.getI());return temp;}
double operator+(Int  left, double  right) {double temp(left.getI()+right);return temp;}
Int operator-(Int  left, Int  right) {Int temp(left.getI()-right.getI());return temp;}
Int operator-(int  left, Int  right) {Int temp(left-right.getI());return temp;}
Int operator-(Int  left, int  right) {Int temp(left.getI()-right);return temp;}
double operator-(double  left, Int  right) {double temp(left-right.getI());return temp;}
double operator-(Int  left, double  right) {double temp(left.getI()-right);return temp;}

Int operator+=(Int & left, Int  right) {Int temp(left.getI()+right.getI());left.i = temp.getI();return temp;} 
Int operator-=(Int & left, Int  right) {Int temp(left.getI()-right.getI());left.i = temp.getI();return temp;}
Int operator-=(Int & left, double  right) {Int temp(left.getI()-right);left.i = temp.getI();return temp;}
 
Int operator*(Int  left, Int  right) {Int temp(left.getI()*right.getI());return temp;}
Int operator*(int  left, Int  right) {Int temp(left*right.getI());return temp;}
Int operator*(Int  left, int  right) {Int temp(left.getI()*right);return temp;}
double operator*(double  left, Int  right) {double temp(left*right.getI());return temp;}
double operator*(Int  left, double  right) {double temp(left.getI()*right);return temp;}
Int operator*=(Int & left, Int  right) {Int temp(left.getI()*right.getI());left.i = temp.getI();return temp;} 
Int operator*=(Int & left, int  right) {Int temp(left.getI()*right);left.i = temp.getI();return temp;}
Int operator*=(Int & left, double  right) {Int temp(left.getI()*right);left.i = temp.getI();return temp;} 


Int operator/(Int  left, Int  right) {Int temp(left.getI()/right.getI());return temp;}
Int operator/(int  left, Int  right) {Int temp(left/right.getI());return temp;}
Int operator/(Int  left, int  right) {Int temp(left.getI()/right);return temp;}
double operator/(double  left, Int  right) {double temp(left/right.getI());return temp;}
double operator/(Int  left, double  right) {double temp(left.getI()/right);return temp;}
Int operator/=(Int & left, Int  right) {Int temp(left.getI()/right.getI());left.i = temp.getI();return temp;} 
Int operator/=(Int & left, int  right) {Int temp(left.getI()/right);left.i = temp.getI();return temp;}
Int operator/=(Int & left, double  right) {Int temp(left.getI()/right);left.i = temp.getI();return temp;}


Int operator%(Int  left, Int  right) {Int temp(left.getI()%right.getI());return temp;}
Int operator%(int  left, Int  right) {Int temp(left%right.getI());return temp;}
Int operator%(Int  left, int  right) {Int temp(left.getI()%right);return temp;}


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
  cout <<  c*d << endl;
  cout <<  1*c << endl;
  cout <<  c*1 << endl;
  cout <<  1.5*c << endl;
  cout <<  c*1.5 << endl;
  cout <<  c*d << endl;
  cout <<  1/c << endl;
  cout <<  c/1 << endl;
  cout <<  1.5/c << endl;
  cout <<  c/1.5 << endl;
}
int main()
{
	f();
}
