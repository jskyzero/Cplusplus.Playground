#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
#include"class.h"
using namespace std;

void main_func(); //������ 
void show_welcome(); // չʾ��ӭ���溯�� 
void show_menu(); //չʾ���˵����� 
bool string_check(string temp);
void inport_string(void);
void exit_system(void);
void exit_system(void)
{
	cout << endl
		<< "----------------------------------------"
		<< "***|------------��������------------|***"
		<< "***|------------ллʹ��------------|***"
		<< "----------------------------------------";
}
void inport_string(void)
{
	cout << endl
		<< "----------------------------------------"
		<< "***|------�������ʽ����------------|***"
		<< "***|-���벻�Ϸ��Ķ���ʽ���ɳ���ѡ��-|***"
		<< "----------------------------------------";
	string str;
	getline(cin,str);
	if (!string_check(str)) cout << "���Ϸ�������" << endl;
	else cout << "�Ϸ�������" << endl;
	cout << "����������������˵�\n";
			
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

void show_welcome()
{
	cout << "----------------------------------------"
		<< "***|---------����ʽ������-----------|***"
		<< "***|��ӭʹ��-------------��ǰ�汾1.0|***"
		<< "----------------------------------------";
}
void show_menu()
{
	cout << endl
		<< "----------------------------------------"
		<< "***|------�˵�����------------------|***"
		<< "***|------���¶�Ӧ�����ּ���ѡ��----|***"
		<< "----------------------------------------"
		<< "1.�������ʽ                            "
		<< "2.����ʽ���                            "
		<< "3.����ʽ���                            "
		<< "4.����ʽ�볣���ĳ˷�����                "
		<< "5.�����ʽ����ĳ���ֵ                  "
		<< "6.��ʾ���д������ʽ                    "
		<< "7.�������鿴�����б�                  "
		<< "8.�߼����ܣ����ӹ��ܣ�                  "
		<< "9.�������鿴�����б�                  "
		<< "0.�˳�ϵͳ                              "
		<< "----------------------------------------"
		<< "***|--------------------------------|***"
		<< "***|--------------------------------|***"
		<< "----------------------------------------"
		<< "���������֣���ע��ÿ��ֻ����һ�����֣�";
}
void main_func()
{
	char choice = '1';
	while ('0' != choice) {
		system("cls");
		show_welcome();
		cout << endl;
		show_menu();
		choice = getche();
		switch (choice) {

		case'1':
			system("cls");
			show_welcome();
			inport_string();
			char temp1;
			temp1 = getche();
			break;
		case'2':
			system("cls");
			show_welcome();
			break;
		case'3':
			system("cls");
			show_welcome();
			break;
		case'4':
			system("cls");
			show_welcome();
			break;
		case'5':
			system("cls");
			show_welcome();
			break;
		case'6':
			system("cls");
			show_welcome();
			break;
		case'7':
			system("cls");
			show_welcome();
			break;
		case'8':
			system("cls");
			show_welcome();
			break;
		case'9':
			system("cls");
			show_welcome();
			break;
		case'0':
			system("cls");
			show_welcome();
			exit_system(); 
			break;
		default:
			system("cls");
			show_welcome();
			cout << "��Ǹ��Ч������\n";
			cout << "����������������˵�\n";
			char temp0;
			temp0 = getche();
			
			break;
		}
	}

}


