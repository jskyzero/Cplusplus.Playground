#include<iostream>
#include<cstring>
#include<fstream>
#include"= =.h"
using namespace std;

	//进书 
	//进书，对应进书模块，表示当前进入一批数量为count的name书籍
bool add_books(char name[], int count)
	{
		ifstream in_file;
		in_file.open("date.txt");
		ofstream out_file;
		out_file.open("temp.txt");
		
		
	
		
		
		Books file_books;
		int samename,flag = 0;
		
	while(! in_file.eof()) {
		if(in_file  >> file_books.name && in_file >> file_books.count) {
			samename = strcmp(file_books.name, name);
		
			if(0 == samename) {
			flag = 1;
			file_books.count += count;
		} 
		out_file << file_books.name
		 		 << endl
		 		 << file_books.count
				 << endl;
			
		}
	}
		
		if(0 == flag) {
		out_file << name
				 << endl
		 		 << count
				 << endl;	
	}
		
		in_file.close();
		out_file.close();
		
		ifstream in_file2;
		in_file2.open("temp.txt");
		ofstream out_file2;
		out_file2.open("date.txt");
		
		while(! in_file2.eof()) {
		if(in_file2  >> file_books.name && in_file2 >> file_books.count) {
		
		out_file2 << file_books.name
				  << endl
		 		  << file_books.count
		 		  << endl;
		
		}
	}
		in_file2.close();
		out_file2.close();
		return 1;
		
}
	
	//更新库存信息，对应增加库存子功能，对name书籍新增count数量
bool increase_count (char name[], int count)
	{
		
	}
	
	//更新库存列表，对应新增书目子功能，新增name书籍且初始数量为count
bool add_to_list(char name[], int count)
	{
		
	}
	
	
	//借书 
	//借书，对应借书模块，表示当前借出一批数量为count的name书籍
bool delete_books(char name[], int count)
{	ifstream in_file;
	in_file.open("date.txt");
	ofstream out_file;
	out_file.open("temp.txt");
		
		
	
		
		
		Books file_books;
		int samename,flag = 0;
		
	while(! in_file.eof()) {
		if(in_file  >> file_books.name && in_file >> file_books.count) {
			samename = strcmp(file_books.name, name);
		
			if(0 == samename) {
			flag = 1;
			file_books.count = file_books.count - count;
			if( 0 == file_books.count)
				continue;
		} 
		out_file << file_books.name
		 		 << endl
		 		 << file_books.count
				 << endl;
			
		}
	}
		
		if(0 == flag) {
		cout << "can't find the book";	
	}
		
		in_file.close();
		out_file.close();
		
		ifstream in_file2;
		in_file2.open("temp.txt");
		ofstream out_file2;
		out_file2.open("date.txt");
		
		while(! in_file2.eof()) {
		if(in_file2  >> file_books.name && in_file2 >> file_books.count) {
		
		out_file2 << file_books.name
				  << endl
		 		  << file_books.count
		 		  << endl;
		
		}
	}
		in_file2.close();
		out_file2.close();
		return 1;
		
}
	
	//更新库存信息，对应减少库存子功能，对name书籍减少count数量
bool decrease_count(char name[], int count)
{
	
}
 
	
	//更新库存列表，对应删除书籍子功能，删除商品列表中name书籍
bool delete_from_list(char name[])
{
	
} 

	//查询 
	//显示当前书籍列表，包括书籍名及其库存量
void show_books()
{
	ifstream in_file;
	in_file.open("date.txt");
	
	Books file_books;
	while(! in_file.eof()) {
		if(in_file  >> file_books.name && in_file >> file_books.count) {
			cout<< "The book's name is |"
				<< file_books.name
				<< "| and the book's number is |"
				<< file_books.count
				<< "|"
				<< endl;
	}
}
	return;	
}
	
	//查看书库中的name商品
int find_books(char name[])
{
	ifstream in_file;
	in_file.open("date.txt");
	
	Books file_books;
	int samename;
		
	while(! in_file.eof()) {
		if(in_file  >> file_books.name && in_file >> file_books.count) {
			samename = strcmp(file_books.name, name);
		
			if(0 == samename) return file_books.count;
	}
}
	return 0;
}


	//main system 
void main_function(void)
{	
	int inport_number;
	while(1) {
		cout << "\n\n\n___Main system___\n"
			 << "Inport 1 to add_books\n"
		 	 << "Inport 2 to delete_books\n"
		 	 << "Inport 3 to show_books\n"
		 	 << "Inport 4 to find_books\n"
			 << "Inport 0 to quit\n\n";
	
		cin>>inport_number;
	if(1 == inport_number) {	
		cout<<"now, we will add books for you\n\n";
		Books * temp_books_pointer = read_books();
		
		if(!(add_books( temp_books_pointer->name,  temp_books_pointer->count)))
		{
			cout << "sorry, we fail to do that\n"
				 <<	"Please try again\n";

		}
		delete temp_books_pointer;
		
}
	if(2 == inport_number) {	
		cout<<"now, we will delete books for you\n\n";
		Books * temp_books_pointer = read_books();
		
		if(!(delete_books( temp_books_pointer->name,  temp_books_pointer->count)))
		{
			cout << "sorry, we fail to do that\n"
				 <<	"Please try again\n";

		}
		delete temp_books_pointer;
		
}
	if(3 == inport_number) {
		show_books();	
}
	if(4 == inport_number) {
		Books * temp_books_pointer = new Books;
		cout << "Please enter the book's name\n";
		cin >> temp_books_pointer->name;
		int n = find_books(temp_books_pointer->name);
		if(0 == n) 
			cout << "Can't find the book\n";
		else
			cout<< "The book's name is |"
				<< temp_books_pointer->name
				<< "| and the book's number is |"
				<< n
				<< "|"
				<< endl;
		delete temp_books_pointer;
		
}
	
	
	if(0 == inport_number) break;
		
}
	
	return;
}

	//read books
Books * read_books(void)
{	
	Books * temp_books_pointer = new Books;
	
	cout<<"Please enter the book's name\n";
	cin>> (*temp_books_pointer).name;
	cout<<"Please enter the book's number\n";
	cin>> (*temp_books_pointer).count;
	cout<<"So the book's name is |"
		<<(*temp_books_pointer).name
		<<"| and the book's number is |"
		<<(*temp_books_pointer).count
		<<"|"
		<<endl;
	
		return temp_books_pointer;
}
