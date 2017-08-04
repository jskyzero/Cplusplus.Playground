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
     Complex operator+(const Complex & a){
     	Complex temp;
         temp.real = this->real + a.getReal();
         temp.imag = this->imag + a.getImag();
         return temp;
     }
     Complex operator-(const Complex & a){
        Complex temp;
         temp.real = this->real - a.getReal();
         temp.imag = this->imag - a.getImag();
         return temp;
     }
     Complex& operator+=(const Complex & a){
         this->real += a.getReal();
         this->imag += a.getImag();
         return *this;
     }
     Complex& operator-=(const Complex & a){
         this->real -= a.getReal();
         this->imag -= a.getImag();
         return *this;
     }
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

int main () {
	Complex a,b;
 	cout << a;
 	cin >> a;
 	cin >> b;
 	cout << a;
 	cout << b;
 
 	cout << a + b;
 	 a+=b;
 	 cout << a;
 	cout << a- b;
 	 a-=b;
 	 cout <<b;
 	return 0; 
 }
