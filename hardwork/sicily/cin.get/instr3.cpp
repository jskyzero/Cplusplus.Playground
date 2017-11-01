#include<iostream>

int main() {
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	cout<<"Enter your name:\n";
	cin.get(name,ArSize).get();
	cout<<"\n"<<name<<".\n";
	return 0;
	
}
