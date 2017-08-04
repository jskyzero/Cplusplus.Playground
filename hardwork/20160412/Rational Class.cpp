#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

class Rational_Error{
private:
	string err_msg;

public:
	Rational_Error(const string &s) : err_msg(s){}
	string get_message() { return err_msg; }
};

class Rational {
private:
	int num, denom;
	void simplify();	//Reduces fraction to lowest terms
public:
	Rational(int n = 0, int d = 1);
	Rational(const string &);
	Rational &operator+=(const Rational &);
	Rational &operator-=(const Rational &);
	Rational &operator*=(const Rational &);
	Rational &operator/=(const Rational &);
	int numerator() const { return num; }
	int denominator() const { return denom; }
	operator double()const;

	friend istream &operator>>(istream &is, Rational &r);
};

Rational operator+(const Rational &, const Rational &);
Rational operator+(const Rational &);
Rational operator-(const Rational &, const Rational &);
Rational operator-(const Rational &);
Rational operator*(const Rational &, const Rational &);
Rational operator/(const Rational &, const Rational &);

bool operator<(const Rational &, const Rational &);
bool operator<=(const Rational &, const Rational &);
bool operator>(const Rational &, const Rational &);
bool operator>=(const Rational &, const Rational &);
bool operator==(const Rational &, const Rational &);
bool operator!=(const Rational &, const Rational &);

bool operator!(const Rational &);

Rational absValue(const Rational &);

ostream &operator<<(ostream &os, const Rational &r);

static int gcd(int x, int y);

void Rational::simplify()
{
	int d = gcd(abs(num), denom);
	num /= d;
	denom /= d;
}

inline Rational::Rational(int n, int d) :num(n), denom(d)
{
	if (denom == 0)
		throw Rational_Error("Divide-by-zero");
	if (denom < 0)
	{
		denom *= -1;
		num *= -1;
	}
	simplify();
}

Rational::Rational(const string &str)
{
	//Assumes string in form "num / denom"
	static const string validchar = "-0123456789";
	size_t index = 0;

	if ((num == 0 && str.find_first_of(validchar) != 0)
		|| (index == string::npos)
		|| (index != str.find_first_not_of(validchar))
		|| (str.find_first_not_of(validchar, index + 1) != string::npos))

		throw Rational_Error("Invalid fraction");

	denom = atoi(str.c_str() + index + 1);
	if (denom == 0)
		throw Rational_Error("Divide-by-zero");
	simplify();
}

inline Rational::operator double() const
{
	return static_cast<double>(num) / denom;
}

Rational &Rational::operator+=(const Rational &s)
{
	num = num*s.denom + denom*s.num;
	denom *= s.denom;
	simplify();
	return *this;
}

Rational &Rational::operator-=(const Rational &s)
{
	num = num*s.denom - denom*s.num;
	denom *= s.denom;
	simplify();
	return *this;
}

Rational &Rational::operator*=(const Rational &s)
{
	num *= s.num;
	denom *= s.denom;
	simplify();
	return *this;
}

Rational &Rational::operator/=(const Rational &s)
{
	if (s.num == 0)
		throw Rational_Error("Divide-by-zero");
	num *= s.denom;
	denom *= s.num;
	simplify();
	return *this;
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

bool operator!(const Rational&r)
{
	if (r.numerator() == 0)
		return true;

	return false;
}

Rational absValue(const Rational &r)
{
	Rational s(-1, 1);
	if (r.numerator() < 0)
		return s * r;

	return r;
}
Rational operator+ (const Rational &r, const Rational &s)
{
	Rational t = r;
	return t += s;
}

Rational operator+(const Rational &r)
{
	return r;
}

Rational operator-(const Rational &r, const Rational &s)
{
	Rational t = r;
	return t -= s;
}

Rational operator-(const Rational &r)
{
	Rational t(-1, 1);
	return t*r;
}

Rational operator*(const Rational &r, const Rational &s)
{
	Rational t = r;
	return t *= s;
}

Rational operator/(const Rational &r, const Rational &s)
{
	Rational t = r;
	return t /= s;
}

istream &operator>>(istream &is, Rational &r)
{
	char c;
	is >> r.num >> c >> r.denom;
	if (!is || c != '/')
		throw Rational_Error("Invalid fration");
	else r.simplify();
	return is;
}

ostream &operator<<(ostream &os, const Rational &r)
{
	return os << r.numerator() << '/' << r.denominator();
}

int gcd(int x, int y)
{
	int r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
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

	
}
