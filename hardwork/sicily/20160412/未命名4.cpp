// Problem#: 18047
// Submission#: 4640746
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<stdio.h>
using namespace std;

class Rational
{
public:
  Rational();
  Rational(long numerator, long denominator) { this->numerator = numerator; this->denominator = denominator;}
  string toString();
  long num() const { return numerator;}
  long den() const { return denominator;}
  // Define function operators for relational operators
  bool operator<(const Rational &secondRational) const{double a = fun() ; double b = secondRational.fun(); if(a < b) return 1;else return 0;}
  bool operator<=(const Rational &secondRational) const{double a = fun() ; double b = secondRational.fun(); if(a <= b) return 1;else return 0;}
  bool operator>=(const Rational &secondRational) const{double a = fun() ; double b = secondRational.fun(); if(a >= b) return 1;else return 0;}
  bool operator!=(const Rational &secondRational) const{double a = fun() ; double b = secondRational.fun(); if(a != b) return 1;else return 0;}
  bool operator==(const Rational &secondRational) const{double a = fun() ; double b = secondRational.fun(); if(-0,00001 < a-b && a+b <0.00001) return 1;else return 0;}

  // Define function operators for arithmetic operators
  Rational operator+(const Rational &secondRational) const{double a = num(); double b = den(); double c = secondRational.num(); double d = secondRational.den();long n = gcd(a * c + d * b, b * d); Rational temp((a * c + d * b)/n, (b * d)/n); return temp;}
  Rational operator-(const Rational &secondRational) const{double a = num(); double b = den(); double c = secondRational.num(); double d = secondRational.den();long n = gcd(a * c + d * b, b * d); Rational temp((a * c - d * b)/n, (b * d)/n); return temp;}
  Rational operator*(const Rational &secondRational) const{double a = num(); double b = den(); double c = secondRational.num(); double d = secondRational.den();long n = gcd(a * c , b * d); Rational temp((a * c )/n, (b * d)/n); return temp;}
  Rational operator/(const Rational &secondRational) const{double a = num(); double b = den(); double c = secondRational.num(); double d = secondRational.den();long n = gcd(a * d , b * c); Rational temp((a * d )/n, (b * c)/n); return temp;}

  // Define function operators for shorthand operators
  Rational operator+=(const Rational &secondRational){double a = this->num(); double b = this->den(); double c = secondRational.num(); double d = secondRational.den(); this->numerator = a * c + d * b; this->denominator = b * d;}
  Rational operator-=(const Rational &secondRational){double a = this->num(); double b = this->den(); double c = secondRational.num(); double d = secondRational.den(); this->numerator = a * c - d * b; this->denominator = b * d;}
  Rational operator*=(const Rational &secondRational){this->numerator*=secondRational.num(); this->denominator*=secondRational.den();}
  Rational operator/=(const Rational &secondRational){this->numerator*=secondRational.den(); this->denominator*=secondRational.num();}

  // Define function operator []
  long& operator[](const int &index){long a =  num();long b = den();long c = 0; if(1 == index) return b; else if(0 == index) return a ; else return c;}

  // Define function operators for prefix ++ and --
  Rational operator++(){this->numerator += this->denominator; return *this;}
  Rational operator--(){this->numerator -= this->denominator; return *this;}

  // Define function operators for postfix ++ and --
  Rational operator++(int dummy){this->numerator += this->denominator ; return *this;}
  Rational operator--(int dummy){this->numerator -= this->denominator ; return *this;}

  // Define function operators for unary + and -
  Rational operator+(int dummy){this->numerator += this->denominator * dummy; return *this;}
  Rational operator-(int dummy){this->numerator -= this->denominator * dummy; return *this;}

  // Define the output and input operator
  friend ostream &operator<<(ostream &stream, Rational rational);
  friend istream &operator>>(istream &stream, Rational &rational);

  // Define function operator for conversion
  operator double()const {return this->num()/(double)this->den();}
  
  // Add any member needed here
  double fun() const{return this->num()/(double)this->den() ;}
private:
  long numerator;
  long denominator;
  static long gcd(long x, long y){ long t; while(y){ t=x%y; x=y; y=t; }return  x; }
};

Rational::Rational()
{ 
  numerator = 0;  
  denominator = 1; 
}
string Rational::toString()
{
  char s[50];
  if ( denominator == 1) {  
    sprintf(s,"%ld",numerator);
  } else {
    sprintf(s,"%ld/%ld",numerator, denominator);
  }
  return string(s);
}
ostream& operator<<(ostream &str, Rational rational)
{
  str << rational.toString();
  return str;
}
istream &operator>>(istream &str, Rational &rational)
{   char ch;
    str >> rational.numerator>> ch >> rational.denominator; 
}                                 
