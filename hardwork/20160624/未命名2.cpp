#include<iostream>
using namespace std;

template<class T>
void f(T a , T b = 0) {
	cout << "a " << a << " b " << b << endl;
	return ;
}
int main() {
	f(1);
		f(1,2);
	return 0;
}
