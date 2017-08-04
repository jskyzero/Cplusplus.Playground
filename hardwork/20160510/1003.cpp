#include <iostream>
#include <string>
#include<cmath>
using namespace std;

const double PI = acos(-1);

class Shape
{
	public:
	virtual double GetArea() = 0;
	virtual double GetPerim() = 0;
};

class Rectangle : public Shape
{
private:
	double a_,b_;
public:
	Rectangle(double a = 0, double b = 0) {
		a_ = a;
		b_ = b;
	}
	double GetArea() {
		return a_ * b_;
	}
	double GetPerim() {
		return 2* (a_ + b_);
	}
};
class Circle : public Shape
{
private:	double c_;
public:
    Circle(double c) {
    	c_ = c;
	}
	double GetArea() {
		return c_ * c_ * PI;
	}
	double GetPerim() {
		return 2 * c_ * PI;
	} 		
};
int main ()

{

	double n,a,b,c;

	cin>>n;

	for(int i=0;i<n;i++)

	{

		Shape *s;

		cin>>a>>b>>c;

		s = new Rectangle(a,b);

		cout<<s->GetArea()<<" "<<s->GetPerim()<<endl;

		delete s;

		s = new Circle(c);

		cout<<s->GetArea()<<" "<<s->GetPerim()<<endl;

                delete s;

	}

	return 0;

}
