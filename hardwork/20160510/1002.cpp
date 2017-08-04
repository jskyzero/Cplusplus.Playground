#include <iostream>
#include <string>
#include<cmath>

using namespace std;
class Land {
public:
	Land(): price_(0){}
 	Land (int price) {price_ = price;}
	virtual double CalMoney() = 0;
protected:
	int price_;
};
class Square : public Land {
public:
	Square(double len, int price):Land(price){len_ = len;}
	double CalMoney() {return len_* len_* price_;}
private:
	double len_;
};
class Circle : public Land {
public:
	Circle(double radius, int price):Land(price){radius_= radius;}
	double CalMoney() {  return radius_*radius_*price_*acos(-1) ;}
private:
	double radius_;
};
class Accountant {
	public :
		Accountant() : Money_(0){}
		
		void DevelopEstate(Land * land)
		{
			Money_ += land->CalMoney();
		}
		double CheckMoney(){
			return Money_;
		}
	private:
		double Money_;
};


//这里给出一个测试的main函数
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char *argv[]) {
	
  Accountant py;
  Circle *a = new Circle(100, 10000);
  Square *b = new Square(100, 50000);
  py.DevelopEstate(a);
  cout << setprecision(10) << py.CheckMoney() << endl;
  py.DevelopEstate(b);
  cout << setprecision(10) << py.CheckMoney() << endl;

  return 0;
}
