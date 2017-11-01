#include<iostream>
#include<stdlib.h>
using namespace  std;
int main() {
	string temp ="12345678123456789";
	for (int i = 1; i <= temp.length(); i++) {
		cout << temp[i - 1];
		if (0 == i % 4) cout << "	";
	}
	return 0;
}
