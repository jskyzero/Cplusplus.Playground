#include<iostream>
#include<cstring>
#include<fstream>
#include"= =.h"
using namespace std;

int main() {
	cout<<"Hello\n"
		<<"Welcome to use this system\n";
		
	
		
	//main_function();
		ifstream in_file;
		in_file.open("date.txt");
		ofstream out_file;
		out_file.open("temp.txt");
		
		
	
		char *name = "ccc";
		int count = 1;
		
		Books * file_books_pointer = new Books;
		int samename,tag = 0;
	
	if (in_file.good()) {
		cout << "can not open" << endl;
	}
	if (in_file.isopen()) {
		cout << "isopen" << endl;
	}
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
	return 0;	
}
