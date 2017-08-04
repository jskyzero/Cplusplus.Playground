#include<iostream>
#include<cstring>

using namespace std;

//数据结构 
	struct Books {
		char name[100]; //记录书目名
		int count;  //记录书目数量
};

	//进书 
	//进书，对应进书模块，表示当前进入一批数量为count的name书籍
	bool add_books(char name[], int count);
	
	//更新库存信息，对应增加库存子功能，对name书籍新增count数量
	bool increase_count (char name[], int count);
	
	//更新库存列表，对应新增书目子功能，新增name书籍且初始数量为count
	bool add_to_list(char name[], int count); 
	
	
	//借书 
	//借书，对应借书模块，表示当前借出一批数量为count的name书籍
	bool delete_books(char name[], int count);
	
	//更新库存信息，对应减少库存子功能，对name书籍减少count数量
	bool increase_count(char name[], int count);
	
	//更新库存列表，对应删除书籍子功能，删除商品列表中name书籍
	bool delete_from_list(char name[]);


	//查询 
	//显示当前书籍列表，包括书籍名及其库存量
	void show_goods(); 
	
	//查看书库中的name商品
	struct Goods find_goods(char name[]);


	//main system 
void main_function (void);

int main() {
	cout<<"hello\n"
		<<"Welcome to use this system\n";
		
	main_function;
		 
	return 0;	
}

	//main system 
void main_function (void)
{	
	int inport_number;
	while(1) {
		cout<<"___Main system___\n"
			<<"Inport 1 to add_books\n"
			<<"Inport 2 to delete_books\n"
			<<"Inport 0 to quit\n";
	
		cin>>inport_number;
	if(1 == inport_number);
	if(2 == inport_number);
	if(0 == inport_number) break;
		
	}
	
	return;
}
