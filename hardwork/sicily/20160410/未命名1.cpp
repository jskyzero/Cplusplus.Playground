#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1 = "0123456789";
	string s2 = s1.substr(3,2);
	
	cout << s1 << endl; 
	cout << s2 << endl;
	
	cout << s1.erase(3,2) << endl;
	cout << s1.insert(3,s2) << endl;
	cout << s1.replace(3,0,"aa") <<endl ; 
 } 
