#include <iostream>
#include <string>
#include<cmath>
using namespace std;

class Number
{
	private:
		long long  n_;
	public:
		Number(long long n = 0) {
			n_ = n;
		}
		Number& add(long long n) {
			n_ += n;
			return * this;
		}
		Number& sub(long long n) {
			n_ -= n;
			return * this;
		}
		void print()
		{
			cout << n_ <<endl;
		}
 };
 
 int main() {
 	Number n(1);
    n.add(2).sub(3).add(4);
    n.print();
 }
