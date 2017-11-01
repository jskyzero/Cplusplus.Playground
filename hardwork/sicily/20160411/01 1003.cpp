#include<iostream>
using namespace std;


class MyClass
{
    int data;
public:
    MyClass(int d = 0){this->data = d;}  //将d的值赋给data, d值大于0
    void printData() {cout << this->data<<endl;}
    
    //求和1+2+3+...+data，函数返回该和值
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
