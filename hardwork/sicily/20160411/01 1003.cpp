#include<iostream>
using namespace std;


class MyClass
{
    int data;
public:
    MyClass(int d = 0){this->data = d;}  //��d��ֵ����data, dֵ����0
    void printData() {cout << this->data<<endl;}
    
    //���1+2+3+...+data���������ظú�ֵ
    int sumIt() { int i = 1; int N = this->data;int n = 0;for(i;i<=N;i++) n += i; return n;}
};

void f()
{
    MyClass mc(10);
    mc.printData();    
    cout << mc.sumIt() << endl;

    MyClass mc1(100);
    mc1.printData();
    cout << mc1.sumIt() << endl;
    return ;
}
int main()
{
	f();
}
