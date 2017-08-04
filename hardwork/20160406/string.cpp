#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

int main() 
{
	string s1 = "abcdefg";
	string s2 = "01234567";
	string s3 = s1;
	string s4(10, 'x');
	
	cout << s1 << endl
		<< s2 << endl
		<< s3 << endl
		<< s4 << endl; 
	
	cout << s2.substr(5,5) << endl
		<< s2 << endl;
	char * p =  new char [s1.size()];
	strcpy(p,&s1[0]);
	printf("%s", p);
}
