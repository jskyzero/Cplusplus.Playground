
#include<iostream>
#include<conio.h>
#include <ctime>

using namespace std;

void MainFunc(void);
string GetTime(void);

void MainFunc(void)
{
	char ch;
	ch = _getch();
}

string GetTime(void)
{
	string str;
	errno_t err;
	time_t nowtime = time(NULL);
	str = ctime(&nowtime);
	if (err != 0)
	printf("Invalid Arguments for ctime_s. Error Code: %d\n", err);
	return str;
}

int main()
{
	cout << GetTime();
}
