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
	bool add_goods(char name[], int count);
	
	//���¿����Ϣ����Ӧ���ӿ���ӹ��ܣ���name�鼮����count����
	bool increase_count (char name[], int count);
	
	//���¿���б���Ӧ������Ŀ�ӹ��ܣ�����name�鼮�ҳ�ʼ����Ϊcount
	bool add_to_list(char name[], int count); 
	
	
	//���� 
	//���飬��Ӧ����ģ�飬��ʾ��ǰ���һ������Ϊcount��name�鼮
	bool delete_goods(char name[], int count);
	
	//���¿����Ϣ����Ӧ���ٿ���ӹ��ܣ���name�鼮����count����
	bool increase_count(char name[], int count);
	
	//���¿���б���Ӧɾ���鼮�ӹ��ܣ�ɾ����Ʒ�б���name�鼮
	bool delete_from_list(char name[]);


	//��ѯ 
	//��ʾ��ǰ�鼮�б������鼮����������
	void show_goods(); 
	
	//�鿴����е�name��Ʒ
	struct Goods find_goods(char name[]);


int main() {
	cout<<"hello\n"
		<<"Welcome to use this system\n"
		<<"Let me know what you want to do\n";
		 
	return 0;	
}
