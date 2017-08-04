#include<iostream>

using namespace std;


int time,num,card[52];

void read()
{
	cin >> num;
	for(int i = 0; i < 52 ; i++) {
		cin >> card[i];
	}
}

bool game() 
{
	return 1;
}

void output(int i)
{
	cout << "Case "<< i <<": ";
		if(game()) 
			cout << "";
		else 
			cout << "unwinnable";
		
		cout << endl;
	}


int main()
{
	cin >> time;
	for(int i = 1; i <= time ;i++) {
		read();
		
		output(i);
		
	}
	return 0;
}
