#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

//���ݽṹ 
	struct Books {
		char name[100]; //��¼��Ŀ��
		int count;  //��¼��Ŀ����
};

	//���� 
	//���飬��Ӧ����ģ�飬��ʾ��ǰ����һ������Ϊcount��name�鼮
bool add_books(char name[], int count);
	
	//���¿����Ϣ����Ӧ���ӿ���ӹ��ܣ���name�鼮����count����
bool increase_count (char name[], int count);
	
	//���¿���б���Ӧ������Ŀ�ӹ��ܣ�����name�鼮�ҳ�ʼ����Ϊcount
bool add_to_list(char name[], int count); 
	
	
	//���� 
	//���飬��Ӧ����ģ�飬��ʾ��ǰ���һ������Ϊcount��name�鼮
bool delete_books(char name[], int count);
	
	//���¿����Ϣ����Ӧ���ٿ���ӹ��ܣ���name�鼮����count����
bool increase_count(char name[], int count);
	
	//���¿���б���Ӧɾ���鼮�ӹ��ܣ�ɾ����Ʒ�б���name�鼮
bool delete_from_list(char name[]);


	//��ѯ 
	//��ʾ��ǰ�鼮�б������鼮����������
void show_goods(); 
	
	//�鿴����е�name��Ʒ
struct Goods find_goods(char name[]);


	//main system 
void main_function(void);


	//read books
Books* read_books(void);








int main() {
	cout<<"Hello\n"
		<<"Welcome to use this system\n";
		main_function();
		
		return 0;
}

	
	
	
	//���� 
	//���飬��Ӧ����ģ�飬��ʾ��ǰ����һ������Ϊcount��name�鼮
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
	
	//���¿����Ϣ����Ӧ���ӿ���ӹ��ܣ���name�鼮����count����
bool increase_count (char name[], int count)
	{
		
	}
	
	//���¿���б���Ӧ������Ŀ�ӹ��ܣ�����name�鼮�ҳ�ʼ����Ϊcount
bool add_to_list(char name[], int count)
	{
		
	}

	//main system 
void main_function(void)
{	
	int inport_number;
	while(1) {
		cout << "\n\n\n___Main system___\n"
			 << "Inport 1 to add_books\n"
		 	 << "Inport 2 to delete_books\n"
			 << "Inport 0 to quit\n\n";
	
		cin>>inport_number;
	if(1 == inport_number)
	{	
		cout<<"now, we will add books for you\n\n";
		Books * temp_books_pointer = read_books();
		
		if(!(add_books( temp_books_pointer->name,  temp_books_pointer->count)))
		{
			cout << "sorry, we fail to do that\n"
				 <<	"Please try again\n";

		}
		delete temp_books_pointer;
		
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


		

