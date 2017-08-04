#include<iostream>
#include<string>

using namespace std;
bool string_check(string temp);
void inport_string(void);


void inport_string(void)
{
	cout << "inport_string\n";
	string str;
	getline(cin,str);
	if (!string_check(str)) cout << "error" << endl;
	else cout << "right" << endl;


}
bool string_check(string temp)
{
	int whiteChar_index = 0;
	int someChar_index = 0;
	int leftChar_index = 0;
	int rightChar_index = 0;
	int midChar_index = 0;
	int endChat_index = 0;
	
	
	while (whiteChar_index = temp.find(' ')) {
		if (-1 == whiteChar_index) {
			break;
		}
		else temp.erase(whiteChar_index, 1);
	}
	temp += '#';
	someChar_index = temp.find('=');
	if(-1 == someChar_index || 0 == someChar_index) return 0;
	else {
		for (int i = 0; i < someChar_index; i++) {
		if (!isalpha(temp[i])) {
			return 0;
			}
		}
	}
	temp.erase(0, someChar_index + 1);
	
	while (temp != "#") {
		leftChar_index = temp.find('(');
		rightChar_index = temp.find(')');
		midChar_index = temp.find(',');
		if ((-1 == leftChar_index || -1 == rightChar_index) || -1 == midChar_index) {
			if (!((-1 == leftChar_index && -1 == rightChar_index) && -1 == midChar_index)) {
				return 0;
			}
			else {
				if(temp != "#") return 0;
			}
		}
		else {
			if (',' == temp[leftChar_index + 1]) {
				return 0;
			}
			for (int i = leftChar_index + 1; i < midChar_index; i++) {
				if (!isdigit(temp[i])) {
					return 0;
				}
			}
			if (')' == temp[midChar_index + 1]) {
				return 0;
			}
			for (int i = midChar_index + 1; i < rightChar_index; i++) {
				if (!isdigit(temp[i])) {
					return 0;
				}
			}
			temp.erase(leftChar_index, rightChar_index - leftChar_index + 1);
		}

	} return 1;

}

int main()
{
	while(1){
		inport_string();	
	}
}
