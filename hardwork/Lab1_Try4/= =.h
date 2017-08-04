#include<iostream>
#include<cstring>
#include<fstream>

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
bool decrease_count(char name[], int count);
	
	//更新库存列表，对应删除书籍子功能，删除商品列表中name书籍
bool delete_from_list(char name[]);


	//查询 
	//显示当前书籍列表，包括书籍名及其库存量
void show_books(); 
	
	//查看书库中的name商品
int find_books(char name[]);


	//main system 
void main_function(void);


	//read books
Books* read_books(void);
