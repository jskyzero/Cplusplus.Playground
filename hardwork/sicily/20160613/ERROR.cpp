#include<iostream>

using namespace std;

#define ERROR1 "ERROR"
double mySqrt(double Dnum) {
	if(Dnum < 0) throw "123";
	else return Dnum;
}

int main() {
	double n = -1.2;
	try {
		try {
			double N = mySqrt(n);
			cout << N ;
		}

		catch(char const * temp) {
				cout << temp <<endl;
			throw 2;
		}
		catch(int n) {
		cout << n << "1"<<endl;
	}
		cout << "1\n";
	} 
	catch(int n) {
		cout << n << "2"<<endl;
	}
	 catch(...) {
		cout << "...\n";
	}
	
	getchar();
}
//abcdefghijklmnopqrstuvwxyz 
//abcdefghijklnbopqrstuvwxyz
