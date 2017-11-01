#include<iostream>
#include<cstring>

using namespace std;

char b[] = "abc";
void f(char a[10]  = &b[0]) 
{
	cout << a << endl;
	cout << a[10] << endl;
	cout << a[0] << endl; 
}
int main()
{
	char a[10] = {'1','2','3','4','5'};
	cout << a << endl;
	cout << a[10] << endl;
	cout << a[0] << endl;
	f();
}
