#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	istringstream src("This \0 is ");
	string word;
	while(src >> word) {
		cout << word << endl;
	}
	src.clear();
	src.str("a b c");
	while(src >> word) {
		cout << word << endl;
	}
		while(cin >> word) {
		cout << word << endl;
	}
	
}
