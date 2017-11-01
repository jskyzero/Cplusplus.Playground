#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>
#define num number
#define denom denominator
using namespace std;
using namespace std;

class Rational
{
public:
  Rational();
  Rational(const string &str){
	//Assumes string in form "num / denom"
	static const string validchar = "-0123456789";
	size_t index = 0;

	if ((numerator == 0 && str.find_first_of(validchar) != 0)
		|| (index == string::npos)
		|| (index != str.find_first_not_of(validchar))
		|| (str.find_first_not_of(validchar, index + 1) != string::npos));
	denominator = atoi(str.c_str() + index + 1);
	simplify();
}
  Rational(long numerator, long denominator) { this->numerator = numerator; this->denominator = denominator;if (denominator< 0)denominator*= -1;numerator*= -1;simplify();}
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
  Rational & operator+=(const Rational &s)
{
	num = num*s.denom + denom*s.num;
	denom *= s.denom;
	simplify();
	return *this;
}
{
	num = num*s.denom - denom*s.num;
	denom *= s.denom;
	simplify();
	return *this;
}

Rational &operator*=(const Rational &s)
{
	num *= s.num;
	denom *= s.denom;
	simplify();
	return *this;
}

Rational &operator/=(const Rational &s)
{
	num *= s.denom;
	denom *= s.num;
	simplify();
	return *this;
}
  // Define function operator []
  long& operator[](const int &index){long a =  num();long b = den();long c = 0; if(1 == index) return b; else if(0 == index) return a ; else return c;}

  // Define function operators for prefix ++ and --
  Rational operator++(){this->numerator += this->denominator; return *this;}
  Rational operator--(){this->numerator -= this->denominator; return *this;}

  // Define function operators for postfix ++ and --
  Rational operator++(int dummy){this->numerator += this->denominator * dummy; return *this;}
  Rational operator--(int dummy){this->numerator -= this->denominator * dummy; return *this;}

  // Define function operators for unary + and -
  Rational operator+(int dummy){this->numerator += this->denominator * dummy; return *this;}
  Rational operator-(int dummy){this->numerator -= this->denominator * dummy; return *this;}

  // Define the output and input operator
  friend ostream &operator<<(ostream &stream, Rational rational);
  friend istream &operator>>(istream &stream, Rational &rational);

  // Define function operator for conversion
inline Rational::operator double() const{ return static_cast<double>(num) / denom;} 
  
  // Add any member needed here
  double fun() const{return this->num()/(double)this->den() ;}
  void simplify(){ int d = gcd(abs(numerator), denominator);numerator /= d;denominator/= d;}
private:
  long numerator;
  long denominator;
  static long gcd(long x, long y){ long t; while(y){ t=x%y; x=y; y=t; }return  x; }
};

Rational::Rational(){ numerator = 0; denominator = 1; }

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
{	char ch;
	str >> rational.numerator>> ch >> rational.denominator; 
}

int main()
{
	Rational a1(3,5);
	Rational a2;
	Rational a3(5,8);
	Rational a4;
	
	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
	
	cout << ++a1 << endl;
	cout << a2-- << endl;	
	cout << a1.toString() << endl;

	Rational r(2, 3);
	Rational s(3, 4);
	Rational t(6, 8);
	Rational u(-4, 7);

	if (r < s)
		cout << "True" << endl;

	if (r <= s)
		cout << "True" << endl;

	if (s > r)
		cout << "True" << endl;

	if (s >= t)
		cout << "True" << endl;

	if (s == t)
		cout << "s = t" << endl;

	if (s != r)
		cout << "true" << endl;

	

	system("Pause");

	
}
