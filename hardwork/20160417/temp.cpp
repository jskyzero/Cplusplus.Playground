#include<iostream>
#include<string> 
using namespace std;

int main()
{
	string str = "p = (2,1)(1,0)";
	string name;//多项式的代称；
	int a[1000];//保存正的幂数的系数；
	int b[1000];//保存负的幂数的系数；
	int whiteChar_index = 0;
	int someChar_index = 0;
	int leftChar_index = 0;
	int rightChar_index = 0;
	int midChar_index = 0;
	int endChat_index = 0;
	while(whiteChar_index = str.find(' ')) {
		if(' ' == str[whiteChar_index]) {
				str.erase(whiteChar_index,1);
				cout << str << endl;
		} else break; 
	}

	str += '#';
	string temp = str;
	
	
	someChar_index = temp.find('=');
	
	
	bool right_str = 1;
	for(int i = 0; i < someChar_index; i++) {
		if(!isalpha(temp[i])) {
			right_flag = 0;
			break;
		}
	}
	while(temp != "#"){
		
		leftChar_index = temp.find('(');
		rightChar_index = temp.find(')');
		midChar_index = temp.find(',');
		
			
	}
	 


	
	 
	 
}
