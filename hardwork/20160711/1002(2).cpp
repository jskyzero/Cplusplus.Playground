//jskyzero 20160711

#include<iostream>
#include<cmath>

using namespace std;

#define NumLimit 1001 // 1 <= n < m <= 1000
#define PrimeLimit 10001 // 10 * 1000 + 1

int prime[PrimeLimit];
int num[NumLimit];

int n, m, x;

bool isPrime(int n) {
	if(1 == n || 0 == n) return 0;
	for( int i = 2; i <= sqrt(n) ; i++) {
		if(0 == n % i ) return 0;
	}
	return 1;
}

void setPrime(int n) {
	while(n--) {
		prime[n] = (isPrime(n) ? 1 : 0);

	}
	prime[0] = 0;
}

bool isOK(int column, int number) {
	for(int i = n; i < column ; i++) {
		if(num[i] == number) return 0;
	}

	for(int i = column -1 ; i >= n && i >= column - x + 1 ; i--) {
	
		number += num[i];
		if(1 == prime[number]) {
			return 0;
		}
	}
	return 1;
}

bool DFS(int column) {
	if(column == m + 1) {
		for(int i = n; i <= m; i++) {
			cout << num[i] <<((i == m)? "" : "," );
		}
		cout << endl;
		return 1;
	}
	for(int i = n; i <= m; i++) {

		num[column] = i;
		if(isOK(column, i) && DFS(column+1)) return 1;

	}
	return 0;
}

int main() {
	setPrime(PrimeLimit);
	cin >> n >> m >> x;
	while(n || m || x) {
		if(!DFS(n)) cout <<"No anti-prime sequence exists.\n";
		cin >> n >> m >> x;
	}
	return 0;
}
