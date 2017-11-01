#include <string>
#include <iostream>
using namespace std;
class Complex
 {
 public:
     Complex(): real(0), imag(0) {}
     Complex(int a, int b): real(a), imag(b) {}
     int getReal() const { return real; }
     int getImag() const { return imag; }
	 friend Complex operator +(Complex left, Complex right);
	  Complex& operator +=( Complex right){this->real += right.real; this->imag += right.imag;return *this;}
	 friend Complex operator -(Complex left, Complex right);
	  Complex& operator -=( Complex right){this->real -= right.real; this->imag -= right.imag;return *this;}
     
	 int real;
     int imag;
     
      friend istream& operator>>(istream&, Complex&);
     friend ostream& operator<<(ostream&, const Complex&);
 };
     Complex operator + (Complex left, Complex right) {Complex temp;temp.real = left.real + right.real; temp.imag = left.imag + right.imag;return temp;}
     Complex operator - (Complex left,Complex right) {Complex temp;temp.real = left.real - right.real; temp.imag = left.imag - right.imag;return temp;}
     
     #include <string>
#include <iostream>
using namespace std;
class Complex;
istream& operator>>(istream&, Complex&);
ostream& operator<<(ostream&, const Complex&);

ostream& operator << ( ostream& out, const Complex& x)
{
	out << x.real ;
	if(x.imag >= 0 ) cout << '+';
	
	cout << x.imag << 'i';               

	return out;
}

istream& operator >> (istream& in, Complex& x)
{
	char temp;
	in >> x.real;
	in >> x.imag;
	in >> temp;

	return in;
}
 Complex operator*(const Complex& a, const Complex& b){
 	Complex temp(a.real * b.real - a.imag * b.imag, a.imag * b.real + a.real * b.imag);
 	return temp;
 }
 int main () {
	Complex a,b;
 	cout << a;
 	cin >> a;
 	cin >> b;
 	cout << a;
 	cout << b;
 	cout << a* b;
 	cout << a + b;
 	cout << a+=b;
 	cout << a- b;
 	cout << a-=b;
 	return 0; 
 }
 
 
