#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1 = "0123456789";
	string s2 = s1.substr(2,3);
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s1.substr(2,3) << endl;
	cout << s1 << endl;
	cout << s1.erase(2,3) << endl;
	cout << s1 << endl;
	cout << s1.insert(2,s2) <<endl;
	cout << s1.replace(2,0,"***") << endl;
 } 
