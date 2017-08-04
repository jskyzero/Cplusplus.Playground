// Problem#: 18047
// Submission#: 4641829
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<cstdlib>
#include<string>
#include<stdio.h>
#include<cmath>
using namespace std;
class Rational
{
public:
  Rational();
  Rational(long a, long b){numerator=a;denominator=b;};
  string toString();

  // Define function operators for relational operators
  bool operator<(const Rational &secondRational) const;
  bool operator<=(const Rational &secondRational) const;
  bool operator>=(const Rational &secondRational) const;
  bool operator!=(const Rational &secondRational) const;
  bool operator==(const Rational &secondRational) const;

  // Define function operators for arithmetic operators
  Rational operator+(const Rational &secondRational) const;
  Rational operator-(const Rational &secondRational) const;
  Rational operator*(const Rational &secondRational) const;
  Rational operator/(const Rational &secondRational) const;

  // Define function operators for shorthand operators
  Rational operator+=(const Rational &secondRational);
  Rational operator-=(const Rational &secondRational);
  Rational operator*=(const Rational &secondRational);
  Rational operator/=(const Rational &secondRational);

  // Define function operator []
  long& operator[](const int &index);

  // Define function operators for prefix ++ and --
  Rational operator++();
  Rational operator--();

  // Define function operators for postfix ++ and --
  Rational operator++(int dummy);
  Rational operator--(int dummy);

  // Define function operators for unary + and -
  Rational operator+();
  Rational operator-();

  // Define the output and input operator
  friend ostream &operator<<(ostream &stream, Rational &rational);
  friend istream &operator>>(istream &stream, Rational &rational);

  // Define function operator for conversion
  operator double(){
    double a1= numerator;
    double a2=denominator;
    return a1/a2;
  }
  private:
  long numerator;
  long denominator;
  static long gcd(long n, long d);
};
istream &operator>>(istream &is, Rational &b){
    char a;
    is>>b.numerator>>a>>b.denominator;
    return is;
}
long& Rational::operator[](const int &index){
    if(index==0)
    return numerator;
    return denominator;
}
long Rational::gcd(long a, long b){
    return b==0?a:gcd(b,a%b);
}

Rational Rational::operator+(const Rational &b) const{
     long a1=numerator*b.denominator+denominator*b.numerator;
     long a2=denominator*b.denominator;
    long t=gcd(a1,a2);
    a1/=t;
    a2/=t;
    Rational temp(a1,a2);
    return temp;
}
Rational Rational::operator-(const Rational &b) const{
     long a1=numerator*b.denominator-denominator*b.numerator;
     long a2=denominator*b.denominator;
    long t=gcd(a1,a2);
    a1/=t;
    a2/=t;
    Rational temp(a1,a2);
    return temp;
}
Rational Rational::operator*(const Rational &b) const{
    long a1=numerator*b.numerator;
    long a2=denominator*b.denominator;
    long t=gcd(a1,a2);
    a1/=t;
    a2/=t;
    Rational temp(a1,a2);
    return temp;
}
Rational::Rational()
{ 
  numerator = 0;  
  denominator = 1; 
}
Rational Rational::operator/(const Rational &b) const{
     long a1=numerator*b.denominator;
     long a2=denominator*b.numerator;
    long t=gcd(a1,a2);
    a1/=t;
    a2/=t;
    Rational temp(a1,a2);
    return temp;
}
bool Rational::operator<(const Rational &b) const{
    double a1=numerator/denominator;
    double a2=b.numerator/b.denominator;
    return (a1<a2);
}
bool Rational::operator<=(const Rational &b) const{
    double a1=numerator/denominator;
    double a2=b.numerator/b.denominator;
    return (a1<=a2);
}
bool Rational::operator>=(const Rational &b) const{
        double a1=numerator/denominator;
    double a2=b.numerator/b.denominator;
    return (a1>=a2);
}
bool Rational::operator!=(const Rational &b) const{
        double a1=numerator/denominator;
    double a2=b.numerator/b.denominator;
    return (a1!=a2);
}
bool Rational::operator==(const Rational &b) const{
        double a1=numerator/denominator;
    double a2=b.numerator/b.denominator;
    return (a1==a2);
}
Rational Rational::operator+=(const Rational &b){
    *this=*this+b;
    return *this;
}
Rational Rational::operator-=(const Rational &b){
    *this=*this-b;
    return *this;
}
Rational Rational::operator*=(const Rational &b){
    *this=*this*b;
    return *this;
}
Rational Rational::operator/=(const Rational &b){
    *this=*this/b;
    return *this;
}
Rational Rational::operator++(){
    Rational temp(numerator+denominator,denominator);
    *this=temp;
    return *this;
}
Rational Rational::operator++(int a){
    Rational temp(numerator+denominator,denominator);
    Rational temp1=*this;
    *this=temp;
    return temp1;
}
Rational Rational::operator--(){
    Rational temp(numerator-denominator,denominator);
    *this=temp;
    return *this;
}
Rational Rational::operator--(int a){
    Rational temp(numerator-denominator,denominator);
    Rational temp1=*this;
    *this=temp;
    return temp1;
}
Rational Rational::operator+(){
        Rational temp(numerator,denominator);

    return temp;
}
Rational Rational::operator-(){
    Rational temp(-numerator,-denominator);
    return temp;
}


string Rational::toString()
{
  char s[50];
  if ( denominator == 1) {  
    sprintf(s,"%ld",numerator);
  } else {
    sprintf(s,"%ld/%ld",numerator,denominator);
  }
  return string(s);
}
ostream& operator<<(ostream &str, Rational &rational)
{
  cout << rational.toString();
  return str;
}                                                       

