#include<iostream>
#include<iomanip>
using namespace std;
 
int main() {
	double f = 123.456789;

	
	cout << setprecision(2);
	string str = "huangjintian";
	cout << setw(30) << f << endl;
	cout << setw(30) << str << endl;
} 
