#include <string>
#include <iostream>
using namespace std;
class Complex
 {
 public:
     Complex(int a=0, int b=0): real(a), imag(b) {}
     friend Complex operator*(const Complex&, const Complex&);
     friend istream& operator>>(istream&, Complex&);
     friend ostream& operator<<(ostream&, const Complex&);
 private:
     int real;
     int imag;
 };
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



 
 int main() {
 	Complex a,b;
 	cout << a;
 	cin >> a;
 	cin >> b;
 	cout << a;
 	cout << b;
 	cout << a* b;
 	return 0;
 }




