#include<iostream>
using namespace std;
class A
{
public:
	int a ;	
};
class B
{
public:
	int b ;
};
class C : public A, public B
{
public:
	int c ;
};
int main() {
	A a;
	a.a = 1;
	B b;
	b.b = 2;
	C c;
	c.a = 1;
	c.b = 2;
	c.c = 3;
	
	cout << a.a << endl;
	cout << b.b << endl;
	cout << (A)c.a << endl;
}
