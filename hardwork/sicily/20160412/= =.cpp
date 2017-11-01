#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>


using namespace std;

class Rational
{
private:
  long num;
  long den;
  static long gcd(long x, long y)
{
	long r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
  
public:
  Rational();
  Rational(long numerator, long denominator) { 
  	this->num = numerator; 
  	this->den = denominator;
  	if (den< 0) {
	  	den*= -1;
		num*= -1;}
	simplify();
}
  string toString();
  long numerator() const { return num; }
  long denominator() const { return den; }

  // Define function operators for relational operators
friend bool operator<(const Rational &, const Rational &);
friend bool operator<=(const Rational &, const Rational &);
friend bool operator>(const Rational &, const Rational &);
friend bool operator>=(const Rational &, const Rational &);
friend bool operator==(const Rational &, const Rational &);
friend bool operator!=(const Rational &, const Rational &);

  // Define function operators for arithmetic operators
friend Rational operator+(const Rational &, const Rational &);
friend Rational operator+(const Rational &);
friend Rational operator-(const Rational &, const Rational &);
friend Rational operator-(const Rational &);
friend Rational operator*(const Rational &, const Rational &);
friend Rational operator/(const Rational &, const Rational &);

  // Define function operators for shorthand operators
Rational &operator+=(const Rational &);
Rational &operator-=(const Rational &);
Rational &operator*=(const Rational &);
Rational &operator/=(const Rational &);

  // Define function operator []
long& operator[](const int &index) {
	long a = this->numerator();
	long b = this->denominator();
	long c = 0; 
	if(1 == index) return b; 
	else if(0 == index) return a ;
	 else return c;
}

  // Define function operators for prefix ++ and --
Rational operator++(){this->num += this->den; return *this;}
Rational operator--(){this->num -= this->den; return *this;}

  // Define function operators for postfix ++ and --
Rational operator++(int dummy){Rational temp(this->num,this->den);this->num += this->den ; return temp;}
Rational operator--(int dummy){Rational temp(this->num,this->den);this->num -= this->den ; return temp;}

  // Define function operators for unary + and -
Rational operator+(){this->num = this->den; return *this;}
Rational operator-(){this->num = -this->den; return *this;}

  // Define the output and input operator
  friend ostream &operator<<(ostream &stream, Rational rational);
  friend istream &operator>>(istream &stream, Rational &rational);

  // Define function operator for conversion
 operator double() const
{
	return static_cast<double>(num) / den;
}
  
  // Add any member needed here
   void simplify();	//Reduces fraction to lowest terms

};

ostream& operator<<(ostream &str, Rational rational)
{
  str << rational.toString();
  return str;
}
istream &operator>>(istream &str, Rational &rational)
{   char ch;
    str >> rational.num>> ch >> rational.den; 
} 
bool operator<(const Rational &r, const Rational &s)
{
	if ((r.numerator() * s.denominator()) < (s.numerator() * r.denominator()))
		return true;
	else
		return false;

}

bool operator<=(const Rational &r, const Rational &s)
{
	if ((r.numerator() * s.denominator()) > (s.numerator() * r.denominator()))
		return false;
	else
		return true;
}

bool operator>(const Rational &r, const Rational &s)
{
	if ((r.numerator() * s.denominator()) > (s.numerator() * r.denominator()))
		return true;
	else
		return false;
}

bool operator>=(const Rational &r, const Rational &s)
{
	if ((r.numerator() * s.denominator()) < (s.numerator() * r.denominator()))
		return false;
	else
		return true;
}

bool operator==(const Rational &r, const Rational &s)
{
	int left, right;
	left = r.numerator() * s.denominator();
	right = s.numerator() * r.denominator();

	if (left == right)
		return true;

	return false;
}

bool operator!=(const Rational &r, const Rational &s)
{
	int left, right;
	left = r.numerator() * s.denominator();
	right = s.numerator() * r.denominator();

	if (left == right)
		return false;

	return true;
}

void Rational::simplify()
{
	long d = gcd(abs(num), den);
	num /= d;
	den /= d;
}
Rational::Rational()
{ 
  num = 0;  
  den = 1; 
}
string Rational::toString()
{
  char s[50];
  if ( den == 1) {  
    sprintf(s,"%ld",num);
  } else {
    sprintf(s,"%ld/%ld",num,den);
  }
  return string(s);
}


Rational &Rational::operator+=(const Rational &s)
{
	num = num*s.den + den*s.num;
	den *= s.den;
	simplify();
	return *this;
}

Rational &Rational::operator-=(const Rational &s)
{
	num = num*s.den - den*s.num;
	den *= s.den;
	simplify();
	return *this;
}

Rational &Rational::operator*=(const Rational &s)
{
	num *= s.num;
	den *= s.den;
	simplify();
	return *this;
}

Rational &Rational::operator/=(const Rational &s)
{
	
	num *= s.den;
	den *= s.num;
	simplify();
	return *this;
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
	return 0;
	
}
