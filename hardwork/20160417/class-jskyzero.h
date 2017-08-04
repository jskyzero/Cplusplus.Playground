#pragma once
#include<iostream>
#include<string> 
using namespace std;


class Polynomial
{
private:
	string name;//多项式的代称；
	int a[1000];//保存正的幂数的系数；
	int b[1000];//保存负的幂数的系数；
public:
	Polynomial(string a = "");
	bool check_name(string a);// 检查代称对应的多相式；
	static	long double evaluation(Polynomial a);//代入求值
	Polynomial derivation(Polynomial a);//对多项式求导；
	friend bool operator== (Polynomial a, Polynomial b);//判断两个多项式是否相等；
	friend	Polynomial operator*(int a, Polynomial b);//常数与多项式相乘 
	friend	Polynomial operator*(Polynomial a, int b);//常数与多项式相乘 
	friend  Polynomial operator*(Polynomial a, Polynomial b);//两个多项式相乘；
	friend	Polynomial operator+(Polynomial a, Polynomial b);//两个多项式相加；
	friend	Polynomial operator-(Polynomial a, Polynomial b);//两个多项式相减； 
};






