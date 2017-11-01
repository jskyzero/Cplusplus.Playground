#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
#include"class.h"
using namespace std;

void main_func(); //主函数 
void show_welcome(); // 展示欢迎界面函数 
void show_menu(); //展示主菜单函数 
bool string_check(string temp);
void inport_string(void);
void exit_system(void);
void exit_system(void)
{
	cout << endl
		<< "----------------------------------------"
		<< "***|------------结束程序------------|***"
		<< "***|------------谢谢使用------------|***"
		<< "----------------------------------------";
}
void inport_string(void)
{
	cout << endl
		<< "----------------------------------------"
		<< "***|------输入多项式界面------------|***"
		<< "***|-输入不合法的多项式即可撤销选择-|***"
		<< "----------------------------------------";
	string str;
	getline(cin,str);
	if (!string_check(str)) cout << "不合法的输入" << endl;
	else cout << "合法的输入" << endl;
	cout << "输入任意键返回主菜单\n";
			
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
		<< "***|---------多项式计算器-----------|***"
		<< "***|欢迎使用-------------当前版本1.0|***"
		<< "----------------------------------------";
}
void show_menu()
{
	cout << endl
		<< "----------------------------------------"
		<< "***|------菜单界面------------------|***"
		<< "***|------按下对应的数字键来选择----|***"
		<< "----------------------------------------"
		<< "1.输入多项式                            "
		<< "2.多项式相加                            "
		<< "3.多项式相减                            "
		<< "4.多项式与常数的乘法界面                "
		<< "5.求多项式代入某点的值                  "
		<< "6.显示所有储存多项式                    "
		<< "7.帮助（查看功能列表）                  "
		<< "8.高级功能（附加功能）                  "
		<< "9.帮助（查看功能列表）                  "
		<< "0.退出系统                              "
		<< "----------------------------------------"
		<< "***|--------------------------------|***"
		<< "***|--------------------------------|***"
		<< "----------------------------------------"
		<< "请输入数字（请注意每次只输入一个数字）";
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
			cout << "抱歉无效的输入\n";
			cout << "输入任意键返回主菜单\n";
			char temp0;
			temp0 = getche();
			
			break;
		}
	}

}


