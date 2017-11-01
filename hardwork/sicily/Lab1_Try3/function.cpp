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
		
		
	
		
		
		Books * file_books_pointer = new Books;
		int samename,tag = 0;
		
	while(! in_file.eof()) {
		
		in_file>>(*file_books_pointer).name;
		in_file>>(*file_books_pointer).count;
		samename = strcmp((*file_books_pointer).name,name);
		
		if(0 == samename) {
			tag = 1;
			(*file_books_pointer).count += count;
		} 
		out_file<<(*file_books_pointer).name;
		out_file<<endl;
		out_file<<(*file_books_pointer).count;
		out_file<<endl;
		}
		
		if(0 == tag) {
		out_file<<name;
		out_file<<endl;
		out_file<<count;
		out_file<<endl;	
		}
		
		in_file.close();
		out_file.close();
		
		ifstream in_file2;
		in_file2.open("temp.txt");
		ofstream out_file2;
		out_file2.open("date.txt");
		while(! in_file2.eof()) {
		in_file2>>(*file_books_pointer).name;
		in_file2>>(*file_books_pointer).count;
		
		out_file2<<(*file_books_pointer).name;
		out_file2<<endl;
		out_file2<<(*file_books_pointer).count;
		out_file2<<endl;
		}
		in_file2.close();
		out_file2.close();
		
	}
	
	//更新库存信息，对应增加库存子功能，对name书籍新增count数量
	bool increase_count (char name[], int count)
	{
		
	}
	
	//更新库存列表，对应新增书目子功能，新增name书籍且初始数量为count
	bool add_to_list(char name[], int count)
	{
		
	}

	//main system 
void main_function(void)
{	
	int inport_number;
	while(1) {
		cout<<"\n\n\n___Main system___\n"
			<<"Inport 1 to add_books\n"
			<<"Inport 2 to delete_books\n"
			<<"Inport 0 to quit\n\n";
	
		cin>>inport_number;
	if(1 == inport_number)
	{	
		cout<<"now, we will add books for you\n\n";
		Books * temp_books_pointer = read_books();
		
		int add_success = add_books((* temp_books_pointer).name , (* temp_books_pointer).count);
		
	}
	if(2 == inport_number)
	{	
		ifstream in_file;
		in_file.open("date.txt");
		ofstream out_file;
		out_file.open("temp.txt");
		
		
		cout<<"now, we will delete books for you\n\n";
		Books * temp_books_pointer = read_books();
		
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
