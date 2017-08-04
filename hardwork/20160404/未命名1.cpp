#include<iostream>

using namespace std;

int main() 
{
	char str[20];
	cin.getline(str,18,'s');
	cout << str << sizeof(str) << endl;
	
}
