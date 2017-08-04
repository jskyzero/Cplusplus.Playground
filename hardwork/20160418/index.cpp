#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


class index {
private:
	int a[101];
	int b[101];
public:
	index();
	int& operator[](int n);
};
index::index() {
	a[100] = { 0 };
	b[100] = { 0 };
}
int& index::operator[](int n) {
	if (n >= 0)  return a[n];
	else  return b[-n];
}

class Polynomial
{
private:
	string name;//多项式的代称；
	index a;//保存正的幂数的系数；

public:
	Polynomial(string);
	void show_Polynomial(void);
	bool check_name(string a = "");// 检查代称对应的多相式；
	static	long double evaluation(Polynomial a);//代入求值
	Polynomial derivation(Polynomial a);//对多项式求导；
	friend bool operator== (Polynomial a, Polynomial b);//判断两个多项式是否相等；
	friend	Polynomial operator*(int a, Polynomial b);//常数与多项式相乘 
	friend	Polynomial operator*(Polynomial a, int b);//常数与多项式相乘 
	friend  Polynomial operator*(Polynomial a, Polynomial b);//两个多项式相乘；
	friend	Polynomial operator+(Polynomial a, Polynomial b);//两个多项式相加；
	friend	Polynomial operator-(Polynomial a, Polynomial b);//两个多项式相减； 
};
void Polynomial::show_Polynomial(void)
{
	cout << name << "=";
	for (int i = -100;i <= 100; i++) {
		if (0 != a[i]) cout << a[i] << "x^" << i;
	}
	return;
}
Polynomial::Polynomial(string temp) {
	int whiteChar_index = 0;
	int someChar_index = 0;
	int leftChar_index = 0;
	int rightChar_index = 0;
	int midChar_index = 0;
	int endChat_index = 0;
	int index = 0;
	int number = 0;
	while (whiteChar_index = temp.find(' ')) {
		if (-1 == whiteChar_index) {
			break;
		}
		else temp.erase(whiteChar_index, 1);
	}
	cout << temp <<endl;
	temp += '#';
	someChar_index = temp.find('=');
	name = temp.substr(0, someChar_index);
	temp.erase(0, someChar_index + 1);
	cout << temp <<endl;
	while (temp != "#") {
		leftChar_index = temp.find('(');
		rightChar_index = temp.find(')');
		midChar_index = temp.find(',');
		if ((-1 == leftChar_index || -1 == rightChar_index) || -1 == midChar_index) break;
		else {
			string temp_string1 = temp.substr(leftChar_index+1, midChar_index - leftChar_index + 1 - 2);
			string temp_string2 = temp.substr(midChar_index+1, rightChar_index - midChar_index + 1 - 2);
			cout << temp_string1 << endl;
			cout << temp_string2 << endl;
			const char * temp_char1 = temp_string1.c_str();
			const char * temp_char2 = temp_string2.c_str();
			index = atoi(temp_char1);
			a[index] = atoi(temp_char2);
			temp.erase(leftChar_index, rightChar_index - leftChar_index + 1);
		}
	}
	return;

}

int main(){
 Polynomial temp("a=(5,3)");
 temp.show_Polynomial();	
}
