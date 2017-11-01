#include<iostream>
#include<string>

#include<string>
#include<ctime>
#include<iomanip>
#include<list>
using namespace std;

string GetTime(void)
{
	char str[26];
	string str2;
	errno_t err;
	time_t nowtime = time(NULL);
	ctime_s(&str[0], 26, &nowtime);
	str2 = str;
	str2[24] = ' ';
	return str2;
}

int main()
{
	cout << GetTime() <<"A" ;
 } 
