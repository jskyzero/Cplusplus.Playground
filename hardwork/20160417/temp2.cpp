#include<iostream>
#include<string> 
using namespace std;

int main()
{
	string str = "p = (2,1)(1,0)(3,0)(4,0)(5,)";
	string name;//多项式的代称；
	int a[1000];//保存正的幂数的系数；
	int b[1000];//保存负的幂数的系数；

	
string temp = str;

	int whiteChar_index = 0;
	int someChar_index = 0;
	int leftChar_index = 0;
	int rightChar_index = 0;
	int midChar_index = 0;
	int endChat_index = 0;
	while (whiteChar_index = temp.find(' ')) {
		if (' ' == temp[whiteChar_index]) {
			temp.erase(whiteChar_index, 1);
		}
		else break;
	}
	temp += '#';
	someChar_index = temp.find('=');

	bool right_flag = 1;
	for (int i = 0; i < someChar_index; i++) {
		cout << right_flag << endl;
		if (!isalpha(temp[i])) {
			right_flag = 0;
			break;
		}
	}
	temp.erase(0, someChar_index + 1);
	while (temp != "#") {
		leftChar_index = temp.find('(');
		rightChar_index = temp.find(')');
		midChar_index = temp.find(',');
		cout << temp << endl;
		if ((-1 == leftChar_index || -1 == rightChar_index) || -1 == midChar_index) {
			if (!((-1 == leftChar_index && -1 == rightChar_index) && -1 == midChar_index)) {
				right_flag = 0;
				break;
			}
		}
		if (-1 != leftChar_index && -1 != rightChar_index) {
			if (',' == temp[leftChar_index + 1]) {
				right_flag = 0;
				break;
			}
			for (int i = leftChar_index + 1; i < midChar_index; i++) {
				cout << right_flag << endl;
				if (!isdigit(temp[i])) {
					right_flag = 0;
					break;
				}
			}
			if (')' == temp[midChar_index + 1]) {
				right_flag = 0;
				break;
			}
			for (int i = midChar_index + 1; i < rightChar_index; i++) {
				cout << right_flag << endl;
				if (!isdigit(temp[i])) {
					right_flag = 0;
					break;
				}
			}
			temp.erase(leftChar_index, rightChar_index - leftChar_index + 1);
		}

	}
	if (0 == right_flag) cout<<"2";
	else cout<< "1";

	return 0;
}
