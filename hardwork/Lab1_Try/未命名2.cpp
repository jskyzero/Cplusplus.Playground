#include<iostream>
#include<cstring>

using namespace std;

//���ݽṹ 
	struct Books {
		char name[100]; //��¼��Ŀ��
		int count;  //��¼��Ŀ����
};	
	
int main() {
	Books a;
	Books * p = new Books[1];
	cin>>(*p).name;
	cin>>(*p).count;
	if(strcmp("abc",(*p).name) == 0) cout<<"good\n";
	cout<<(*p).name;
	cout<<(*p).count;
	return 0;
}
