#include<iostream>
#include<list>
#include<iomanip>
using namespace std;

list<int> a;
list<int>::iterator it;

int main() {
	a.push_back(1);
		a.push_back(2);
			a.push_back(3);
	for(it = a.begin();it!=a.end();it++) {
			cout << left <<setw(8) << *(it) <<endl;
	}
	return 0;

}
