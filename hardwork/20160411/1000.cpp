#include<iostream>
using namespace std;


int main()
{
	int d , m;
	cin >>  m >> d;
	
	
	while(!((0 == m)&&(0 == d))) {
		int fibOne = 0;
		int fibTwo = 1;
		int fibN = 0;
		if(d < m ) cout << 1;
		else {
			for (int i = 1; i <= d ; i++) {
			fibN = fibOne + fibTwo;
			fibOne = fibTwo;
			fibTwo = fibOne;
			}
			cout << fibN << endl;
			
		}
		cin >>  m >> d;
			
	}
}
