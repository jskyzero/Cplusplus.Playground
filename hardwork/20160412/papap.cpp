#include <cstdio>
#include<iostream>
#include<string>
using namespace std;


class Rational {
public:
	 void check();
  Rational();
  Rational(const Rational& pt) : numerator(pt.numerator), denominator(pt.denominator) {};
  Rational(long _numerator, long _denominator) {
  	if (_numerator == 0) {
  		numerator = 0;
  		denominator = 1;
  	} else {
	  	long tmp = gcd(_numerator, _denominator);
	  	numerator = _numerator / tmp;
	  	denominator = _denominator / tmp;
  	}
  }

  string toString() const;

  // Define function operators for relational operators
  bool operator<(const Rational &sr) const {
  	return (numerator * sr.denominator) < (sr.numerator * denominator);
  }

  bool operator==(const Rational &sr) const {
  	return (numerator * sr.denominator) == (sr.numerator * denominator);
  }

  bool operator>(const Rational &sr) const {
  	return sr < *this;
  }

  bool operator<=(const Rational &sr) const {
  	return !(*this > sr);
  }

  bool operator>=(const Rational &sr) const {
  	return !(*this < sr);
  }

  bool operator!=(const Rational &sr) const {
  	return !(*this == sr);
  }
  

  // Define function operators for arithmetic operators
  Rational operator+(const Rational &sr) const;

  Rational operator-(const Rational &sr) const; 

  Rational operator*(const Rational &sr) const; 
  Rational operator/(const Rational &sr) const ;

  // Define function operators for shorthand operators
  Rational& operator+=(const Rational &sr) {
  	return *this = *this + sr;
  }

  Rational& operator-=(const Rational &sr) {
  	return *this = *this - sr; 
  }

  Rational& operator*=(const Rational &sr) {
  	return *this = *this * sr;
  }

  Rational& operator/=(const Rational &sr) {
  	return *this = *this / sr;
  }

  // Define function operator []
  #if 1
  long& operator[](const int &index) {
  	return index == 0 ? numerator : denominator;
  }
  #endif

  // Define function operators for prefix ++ and --
  Rational& operator++() {
  	return *this += Rational(1, 1);
  }

  Rational& operator--() {
	return *this -= Rational(1, 1);
  }

  // Define function operators for postfix ++ and --
  Rational operator++(int dummy) {
  	Rational tmp(*this);
  	++*this;
  	return tmp;
  }

  Rational operator--(int dummy) {
  	Rational tmp(*this);
  	--*this;
  	return tmp;
  }

  // Define function operators for unary + and -
  Rational operator+() const { return *this; }
  Rational operator-() const { return Rational(-numerator, denominator); }

  // Define the output and input operator
  friend ostream &operator<<(ostream &stream, const Rational &rational);
  friend istream &operator>>(istream &stream, Rational &rational);

  // Define function operator for conversion
  operator double() { return double(numerator) / denominator; }
  
  // Add any member needed here

private:
  long numerator;
  long denominator;
  static long gcd(long a, long b) {
  	long r;
  	while (b > 0) {
  		r = a % b;
  		a = b;
  		b = r;
  	}
  	return a;
  }
};

Rational::Rational()
{ 
  numerator = 0;  
  denominator = 1; 
}

string Rational::toString() const
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
  str << rational.toString();
  return str;
}

istream &operator>>(istream &is, Rational &rational) {
	char c = 0;
	return is >> rational.numerator >> c >> rational.denominator;
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
void Rational::check(){
    long a = numerator;
    long b = denominator;
    long c = gcd(a,b);
    numerator/=c;
    denominator/=c;
}

int main(){
	return 0;
}

