#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream a; // in file
	a.open("abc.txt");
	ofstream b; // out file
	b.open("bcd.txt");
	
	
	int n = 0;
	while(!a.eof()) {
		if (a >> n) {
			cout << "success to input" << endl;
			cout << "n = " << n << endl;
			n++;
			b << n;
			b << endl;
		}
	}
		a.close();
		b.close();
	
	ifstream a2; // in file
	a2.open("bcd.txt");
	ofstream b2; // out file
	b2.open("abc.txt");
	
	
	while(!a2.eof()) {
		a2 >> n;
		
		b2 << n;
		b2 << endl;
	
		
	}
	a2.close();
	b2.close();
	return 0;
}
