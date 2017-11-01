#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

class Rational
{
public:
  Rational();
  Rational(long numerator, long denominator);
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
  operator double(){long a1= numerator;long a2=denominator;return a1/static_cast<double>(a2);}
  // Add any member needed here
  void check();
private:
  long numerator;
  long denominator;
  static long gcd(long n, long d);
};

Rational::Rational()
{ 
  numerator = 0;  
  denominator = 1; 
}
Rational::Rational(long  a, long  b)
{
    numerator = a;
    denominator = b;
    this->check();
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
bool Rational::operator<(const Rational &secondRational) const
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    return (a * b_secondRational < a_secondRational * b );
}
bool Rational::operator<=(const Rational &secondRational) const
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    return (a * b_secondRational <= a_secondRational * b ); 
}
bool Rational::operator>=(const Rational &secondRational) const
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    return (a * b_secondRational >= a_secondRational * b ); 
}
bool Rational::operator!=(const Rational &secondRational) const
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    return (a * b_secondRational != a_secondRational * b ); 
}
bool Rational::operator==(const Rational &secondRational) const
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    return (a * b_secondRational == a_secondRational * b ); 
}
Rational Rational::operator+(const Rational &secondRational) const
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    Rational temp(a*b_secondRational+b*a_secondRational,b*b_secondRational);
    temp.check();
    return temp;
}
Rational Rational::operator-(const Rational &secondRational) const
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    Rational temp(a*b_secondRational-b*a_secondRational,b*b_secondRational);
    temp.check();
    return temp;
}
Rational Rational::operator*(const Rational &secondRational) const
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    Rational temp(a*a_secondRational,b*b_secondRational);
    temp.check();
    return temp;
}
Rational Rational::operator/(const Rational &secondRational) const
{   
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    Rational temp(a*b_secondRational,b*a_secondRational);
    temp.check();
    return temp;
}
Rational Rational::operator+=(const Rational &secondRational)
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    Rational temp(a*b_secondRational+b*a_secondRational,b*b_secondRational);
    temp.check();
    numerator = temp.numerator;
    denominator = temp.denominator;
    return * this;
}
Rational Rational::operator-=(const Rational &secondRational)
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    Rational temp(a*b_secondRational-b*a_secondRational,b*b_secondRational);
    temp.check();
    numerator = temp.numerator;
    denominator = temp.denominator;
    return * this;
}
Rational Rational::operator*=(const Rational &secondRational)
{
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    Rational temp(a*a_secondRational,b*b_secondRational);
    temp.check();
    numerator = temp.numerator;
    denominator = temp.denominator;
    return * this;
}
Rational Rational::operator/=(const Rational &secondRational)
{   
    long a = numerator;
    long b = denominator;
    long a_secondRational = secondRational.numerator;
    long b_secondRational = secondRational.denominator;
    Rational temp(a*b_secondRational,b*a_secondRational);
    temp.check();
    numerator = temp.numerator;
    denominator = temp.denominator;
    return * this;
}
long& Rational::operator[](const int &index)
{
    if(index==0)return numerator;
    return denominator;
}
Rational Rational::operator++()
{
    Rational temp(numerator+denominator,denominator);
    temp.check();
    *this=temp;
    return *this;
}
Rational Rational::operator--()
{
    Rational temp(numerator-denominator,denominator);
    temp.check();
    *this=temp;
    return *this;
}
Rational Rational::operator++(int dummy)
{
    Rational temp(numerator+denominator,denominator);
    temp.check();
    Rational temp1 = *this;
    *this=temp;
    return temp1;
}
Rational Rational::operator--(int dummy)
{
    Rational temp(numerator-denominator,denominator);
    temp.check();
    Rational temp1 = *this;
    *this=temp;
    return temp1;
}
Rational Rational::operator+()
{
    Rational temp(numerator,denominator);
    temp.check();
    return temp;    
}
Rational Rational::operator-()
{
    Rational temp(-numerator,denominator);
    temp.check();
    return temp;    
}
ostream& operator<<(ostream &str, Rational &rational)
{
  str << rational.toString();
  return str;
}
istream& operator>>(istream &is, Rational &b){
        char a;
        is >> b.numerator >> a >> b.denominator;
        return is;
}
void Rational::check(){
    long a = numerator;
    long b = denominator;
    long c = gcd(a,b);
    numerator/=c;
    denominator/=c;
}
long Rational::gcd(long a, long b){
    return b==0?a:gcd(b,a%b);
}                                                                  
