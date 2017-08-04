#include<iostream>

using namespace std;

int main()
{
	double f ( 1.2E-9 );
	cout << f << endl ;
	cout.setf(ios_base::fixed, ios::floatfield + 1);
	cout << f << endl ;
	float f2 = static_cast <float>(f); 
	cout << float (f) << endl ;
	cout << float (f2) << endl ;
	return 0;
}
