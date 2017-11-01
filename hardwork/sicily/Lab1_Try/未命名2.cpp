#include<iostream>
#include<cstring>

using namespace std;

//数据结构 
	struct Books {
		char name[100]; //记录书目名
		int count;  //记录书目数量
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
