#include<iostream>
using namespace std;

class Complex;
ostream & operator<< (ostream & os , Complex& temp );
istream & operator>> (istream& os, Complex& x);


class Complex
{

public:
  
  double real() const { return re; }
  double imag() const { return im; }
  // add any other function needed here
  
  Complex(double a = 0, double b = 0): re(a), im(b) {}
  friend ostream & operator<< (ostream & os , Complex& temp );
  friend istream & operator>> (istream& os, Complex& x);
  friend Complex  operator+(Complex  a, Complex  b);
  friend Complex  operator-(Complex  a, Complex  b);
  friend Complex  operator+=(Complex  a, Complex  b);
  friend Complex  operator-=(Complex  a, Complex  b);
  friend Complex  operator*(Complex  a, Complex  b);
  friend Complex  operator/(Complex  a, Complex  b);
  friend Complex  operator*=(Complex &a, Complex  b);
  friend Complex  operator/=(Complex &a, Complex  b);
 
  friend int  operator==(Complex  a, Complex  b);
  friend int  operator!=(Complex  a, Complex  b);
  Complex& operator =(Complex other)
  { this->im = other.imag(); this->re = other.real(); return * this; }
private:
  double re; //real part of a complex number
  double im; //imaginary part of a complex number
     
};

ostream & operator<< (ostream & os , Complex & temp )
{	double imag = temp.imag() ;
	if(imag > -0.00001 && imag < 0.00001 ) imag = 0;
	double real = temp.real() ;
	if(real > -0.00001 && real < 0.00001 ) imag = 0;
	os << '(' << real << ',' << imag << ')' ;
	return os;  	
}
istream & operator>> (istream& os, Complex& x)
{	char ch;
	double a, b; 
	os >> ch >> a >> ch >> b >> ch;
	x.re = a;
	x.im = b;
	return os;
}

Complex  operator+(Complex  a, Complex  b)
{	
	Complex temp(a.real()+ b.real(), a.imag()+b.imag() );
	return temp;
}
Complex  operator-(Complex  a, Complex  b)
{	
	Complex temp(a.real()-b.real() , a.imag()-b.imag() );
	return temp;
}
Complex  operator-(Complex  a)
{	
	Complex temp(-a.real(), -a.imag());
	return temp;
}
Complex  operator+=(Complex  a, Complex  b)
{	
	Complex temp(a.real()+b.real(), a.imag()+b.imag());
	return temp;
}
Complex  operator-=(Complex a, Complex b)
{	
	Complex temp(a.real()-b.real(), a.imag()-b.imag() );
	return temp;
}
Complex  operator*(Complex a, Complex b)
{	
	Complex temp(a.real()*b.real()-a.imag()*b.imag(), a.real()*b.imag()+b.real()*a.imag());
	return temp;
}
Complex  operator/(Complex  a, Complex  b)
{	
	Complex temp((a.real()*b.real()+a.imag()*b.imag())/(b.real()*b.real()+b.imag()*b.imag()),(a.imag()*b.real()- a.real()*b.imag())/(b.real()*b.real()+b.imag() * b.imag()));
	return temp;
}
Complex  operator*=(Complex &a, Complex  b)
{	
	Complex temp(a.real()*b.real()-a.imag()*b.imag(), a.real()*b.imag()+b.real()*a.imag());
	a = temp;
	return temp;
}
Complex  operator/=(Complex & a, Complex  b)
{	
	Complex temp((a.real()*b.real()+a.imag()*b.imag())/(b.real()*b.real()+b.imag()*b.imag()),(a.imag()*b.real()- a.real()*b.imag())/(b.real()*b.real()+b.imag() * b.imag()));
	a = temp;
	return temp;
}
int   operator==(Complex  a, Complex  b)
{
	if(a.imag() == b.imag() && a.real() == b.real() ) return 1;
	else return 0;
}
int  operator!=(Complex  a, Complex  b)
{
	if(a.imag() == b.imag() && a.real() == b.real() ) return 0;
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
  
  c = c + 2.5; 
  cout << c << endl; 
  
  c = 2.5 + c; 
  cout << c << endl; 

  c -= a;
  cout << c << endl; 
  
  c = c - a;
  cout << c << endl; 

  c = c - 2.5;
  cout << c << endl; 
  
  c = 2.5 - c;
  cout << c << endl; 
  
  c *= b;
  cout << c << endl; 
  
  c = c * b;
  cout << c << endl; 

  c = c * 2.5;
  cout << c << endl; 
  
  c = 2.5 * c;
  cout << c << endl; 
  
  c /= b;
  cout << c << endl; 
  
  c = c / b;
  cout << c << endl; 

  c = c / 2.5;
  cout << c << endl; 
  
  c = 2.5 / c;
  cout << c << endl; 
  
  c = a+2.5+a + b*2.5*b;
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
