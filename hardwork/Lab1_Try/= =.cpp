#include<iostream>
#include<cstring>

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
