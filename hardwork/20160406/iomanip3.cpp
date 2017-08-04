#include <iostream>
#include <iomanip>
using namespace std;
int main() 
{
	int i;
	for( i = 1; i < 1000; i *= 10 )
		cout << setw(6) << i << endl;
	for( i = 1; i < 1000; i *= 10 )
		cout << hex << i << endl;
	int a = 5;
	cout << left << setw(10) << "Karen"
		 << right << setw(6) << a << endl;
	double b = 1234.5;
	cout << setprecision(2);
	cout << setw(8) << b << endl;
	return 0;
}

