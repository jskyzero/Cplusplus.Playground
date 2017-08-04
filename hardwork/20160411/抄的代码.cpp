#include <iostream>

using namespace std;

class Complex
{
public:
    Complex(const Complex &z);
    Complex(double x = 0.0, double y = 0.0);
    ~Complex();
    double real() const {return dat[0];}
    double image() const {return dat[1];}
    
    void set(double x, double y) {dat[0] = x; dat[1] = y;}
    

    Complex operator +(const Complex &other) const;
    Complex operator +(const double &other) const;

    Complex operator -(const Complex &other) const;
    Complex operator -(const double &other) const;

    Complex operator *(const Complex &other) const;
    Complex operator *(const double &other) const;

    Complex operator /(const Complex &other) const;
    Complex operator /(const double &other) const;

    void operator +=(const Complex &other);
    void operator +=(const double &other);

    void operator -=(const Complex &other);
    void operator -=(const double &other);

    void operator *=(const Complex &other);
    void operator *=(const double &other);

    void operator /=(const Complex &other);
    void operator /=(const double &other);

    Complex& operator =(const Complex &other);
    Complex& operator =(const double &other);
    
    friend int  operator==(Complex  a, Complex  b);
    friend int  operator!=(Complex  a, Complex  b);
    friend istream & operator>> (istream& os, Complex& x);
private:
    double dat[2];

    friend std::ostream& operator << (std::ostream&, const Complex & z);
    friend Complex operator -(const Complex &other);


};

istream & operator>> (istream& os, Complex& x)
{	char ch;
	double a, b; 
	os >> ch >> a >> ch >> b >> ch;
	x.dat[0] = a;
	x.dat[1] = b;
	return os;
}
Complex::Complex(double x, double y)  
{  
    dat[0] = x;  
    dat[1] = y;  
}  
  
Complex::Complex(const Complex &z)  
{  
    dat[0] = z.dat[0];  
    dat[1] = z.dat[1];  
}  
  
Complex::~Complex()  
{  
  
}  
  
void Complex::operator +=(const Complex &other)  
{  
    dat[0] += other.dat[0];  
    dat[1] += other.dat[1];  
}  
  
void Complex::operator +=(const double &other)  
{  
    dat[0] += other;  
}  
  
void Complex::operator -=(const Complex &other)  
{  
    dat[0] -= other.dat[0];  
    dat[1] -= other.dat[1];  
}  
  
void Complex::operator -=(const double &other)  
{  
    dat[0] -= other;  
}  
  
void Complex::operator *=(const Complex &other)  
{  
    double x, y;  
    x = (dat[0] * other.dat[0] - dat[1] * other.dat[1]);  
    y = (dat[1] * other.dat[0] + dat[0] * other.dat[1]);  
    dat[0] = x;  
    dat[1] = y;  
}  
  
void Complex::operator *=(const double &other)  
{  
    dat[0] = dat[0] * other;  
    dat[1] = dat[1] * other;  
}  
  
void Complex::operator /=(const Complex &other)  
{  
    double x, y;  
    double a = other.dat[0] * other.dat[0] + other.dat[1] * other.dat[1];  
    x = ((dat[0] * other.dat[0]) + (dat[1] * other.dat[1])) / a;  
    y = ((dat[1] * other.dat[0]) - (dat[0] * other.dat[1])) / a;  
    dat[0] = x;  
    dat[1] = y;  
}  
  
void Complex::operator /=(const double &other)  
{  
    dat[0] = dat[0]/other;  
    dat[1] = dat[1]/other;  
}  
  
Complex Complex::operator+(const Complex &other)  const  
{  
    Complex temp(*this);  
    temp += other;  
    return temp;  
}  
  
Complex Complex::operator +(const double &other) const  
{  
    Complex temp(*this);  
    temp += other;  
    return temp;  
}  
  
Complex Complex::operator -(const Complex &other) const  
{  
    Complex temp(*this);  
    temp -= other;  
    return temp;  
}  
  
Complex Complex::operator -(const double &other) const  
{  
    Complex temp(*this);  
    temp -= other;  
    return temp;  
}  
  
Complex operator -(const Complex &other)  
{  
    Complex temp(-other.real(), -other.image());  
    return temp;  
}  
  
Complex Complex::operator *(const Complex &other) const  
{  
    Complex temp(*this);  
    temp *= other;  
    return temp;  
}  
  
Complex Complex::operator *(const double &other) const  
{  
    Complex temp(*this);  
    temp *= other;  
    return temp;  
}  
  
Complex Complex::operator /(const Complex &other) const  
{  
    Complex temp(*this);  
    temp /= other;  
    return temp;  
}  
  
Complex Complex::operator /(const double &other) const  
{  
    Complex temp(*this);  
    temp /= other;  
    return temp;  
}  
  
Complex& Complex::operator =(const Complex &other)  
{  
    this->dat[0] = other.dat[0];  
    this->dat[1] = other.dat[1];  
    return *this;  
}  
  
Complex& Complex::operator =(const double &other)  
{  
    this->dat[0] = other;  
    this->dat[1] = 0;  
    return *this;  
}  
std::ostream& operator << (std::ostream& out, const Complex & z)  
{  
	out << '(' << z.dat[0] << ',' << z.dat[1]<< ')' ;
     
    return out;  
}

int   operator==(Complex  a, Complex  b)
{
	if(a.dat[0] == b.dat[0] && a.dat[1] == b.dat[1]) return 1;
	else return 0;
}
int  operator!=(Complex  a, Complex  b)
{
	if(a.dat[0] == b.dat[0] && a.dat[1] == b.dat[1]) return 0;
	else return 1;
} 

void f()
{
  Complex a;  
  cout << a << endl; //output (0,0) 
  
  Complex b = Complex(1,2.5); 
  cout << b << endl; //output(1,2.5)
  
  Complex c(3.0); 
  cout << c << endl; //output (3,0)
  
  c += a; 
  cout << c << endl; 
  
  c = c + a; 
  cout << c << endl; 
  Complex a1(2.5);
  c = c + a1; 
  cout << c << endl; 
  
  c = a1 + c; 
  cout << c << endl; 

  c -= a;
  cout << c << endl; 
  
  c = c - a;
  cout << c << endl; 

  c = c - a1;
  cout << c << endl; 
  
  c = a1 - c;
  cout << c << endl; 
  
  c *= b;
  cout << c << endl; 
  
  c = c * b;
  cout << c << endl; 

  c = c * a1;
  cout << c << endl; 
  
  c = a1 * c;
  cout << c << endl; 
  
  c /= b;
  cout << c << endl; 
  
  c = c / b;
  cout << c << endl; 

  c = c / a1;
  cout << c << endl; 
  
  c = a1 / c;
  cout << c << endl; 
  
  c = a+a1+a + b*a1*b;
  cout << c << endl;

  c = -b;
  cout << c << endl;
   
  cout << (a==a) << endl; //output 1
  cout << (a==0.0) << endl; //output 1
  cout << (0.0==a) << endl; //output 1
  cout << (a!=a) << endl; //output 0 
  cout << (a!=0.0) << endl; //output 0
  cout << (0.0!=a) << endl; //output 0  

  cin >> c; //输入格式(a,b)表示复数a + b i
  cout << c << endl;
}

int main()
{
	f();
}
