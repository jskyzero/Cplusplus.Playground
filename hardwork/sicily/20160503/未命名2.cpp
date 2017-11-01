
#include<iostream>
#include<string>
#include<iomanip> 
#include<stdio.h>
using namespace std;

int main()
{
    long long n = 0;
    cin >> n;
    char ch;
    ch = getchar();
    char ch2;
    string temp ;
    while(n) {
    	ch = getchar();
    	if(ch == '\n') n--;
    	if(n<=0) break;
    	temp += ch;
		}
	int N ;
	int Bool = 0;
	while((N = temp.find('*')) > 0) {
		if(1 == Bool) cout << endl;
		cout << temp.substr(0,N);
		Bool = 1;
		temp.erase(0,N+1);
	}
	
	/* int N = temp.length();
	for(int i = N - 1 ; i >= 0; i--) {
		if('*' == temp[i]) temp[i] = '\0';
		else break;
	}
	for(int i = 0; i < N ;i++) {
		if('*' == temp[i]) cout << '\n';
		else 
		cout << temp[i];
	}
	*/
 	return 0;

}                                 
