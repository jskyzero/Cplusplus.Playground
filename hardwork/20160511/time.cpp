#include<iostream>
#include<ctime>

using namespace std;

int main() 
{
	time_t nowtime;
	nowtime = time(NULL);
	nowtime = 1400000000;
	cout << nowtime << endl;
	
	struct tm *  local;
	local = localtime(&nowtime);
	cout << asctime(local)<< endl;
	
	cout << ctime(&nowtime) << endl;
		
}
