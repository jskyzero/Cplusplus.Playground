#include<iostream>
#include<string>
using namespace std;
int main()
{
	string temp;
	temp += "abc\n";
	temp += "123\n";
	cout << "(" << temp << ")" << endl;
	char ch[100]  ;
	cout << temp.c_str() <<endl;
	return 0;
}
