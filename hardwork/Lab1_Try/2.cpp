#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

//���ݽṹ 
	struct Books {
		char name[100]; //��¼��Ŀ��
		int count;  //��¼��Ŀ����
};	
	
int main() {
	ifstream o;
	o.open("=.txt");
	
	
	
	Books a;
	Books * p = new Books[1];
	o>>(*p).name;
	o>>(*p).count;
	if(strcmp("abc",(*p).name) == 0) cout<<"good\n";
	cout<<(*p).name;
	cout<<(*p).count;
	return 0;
}
