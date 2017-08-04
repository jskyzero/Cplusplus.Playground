#include<iostream>
#include<string>

using namespace std;

int main() {
	int n, N;
	cin >> n;
	N = n;
	string str[n+1];
	for(int i = 1; i <= n; i++) {
		cin >> str[i];
	}
	cin >> str[0];
	int boo = 0;
	int n0 = str[0].length();	
	for(int n = 0; n <= n0 ; n++) {
		for(int m = 0; m <= n0; m++) {
			if(n0 < n + m ) break;
			else {
				int n1 = n0-n-m;
				string temp  = str[0].substr(n,n1);
				for(int i = 1; i <= N; i ++){
					if(temp == str[i]) {
					cout << str[i] ;
					n += str[i].length();
					if(n < n0)cout<< " ";
					m = 0;	
					}
				}
			} 
			
		}
		if(boo == 1){
			cout << " ";	
		}
		cout << str[0][n];
		boo = 1;
	}
	cout<<"0";
	return 0;
	
}
