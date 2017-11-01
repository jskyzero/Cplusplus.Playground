#pragma once
#include<iostream>
#include<string> 
using namespace std;


class Polynomial
{
private:
	string name;//����ʽ�Ĵ��ƣ�
	int a[1000];//��������������ϵ����
	int b[1000];//���渺��������ϵ����
public:
	Polynomial(string a = "");
	bool check_name(string a);// �����ƶ�Ӧ�Ķ���ʽ��
	static	long double evaluation(Polynomial a);//������ֵ
	Polynomial derivation(Polynomial a);//�Զ���ʽ�󵼣�
	friend bool operator== (Polynomial a, Polynomial b);//�ж���������ʽ�Ƿ���ȣ�
	friend	Polynomial operator*(int a, Polynomial b);//���������ʽ��� 
	friend	Polynomial operator*(Polynomial a, int b);//���������ʽ��� 
	friend  Polynomial operator*(Polynomial a, Polynomial b);//��������ʽ��ˣ�
	friend	Polynomial operator+(Polynomial a, Polynomial b);//��������ʽ��ӣ�
	friend	Polynomial operator-(Polynomial a, Polynomial b);//��������ʽ����� 
};






