#include<iostream>
using namespace std;


class Int
{	static int num;
    int data;
public:
    Int(int n = 0){data = n;num++;cout << num <<" objects of Int has been constructed.\n";} //将n的值赋给data
    ~Int(){this->num--;}
    static bool isodd(int tempN);
    
};
int Int::num = 0;
bool Int::isodd(int tempN) {if (1 == tempN%2) return 1; else return 0;}
void f()
{
    int i1=1, i2=2;
    cout << "num " << i1 << " is odd? " << Int::isodd(1) << endl;    
    cout << "num " << i2 << " is odd? " << Int::isodd(2) << endl;    
    Int ii1; 
    { Int ii1(i1); }
    Int ii2(i2);
    return;
}
int main()
{
	f();
}
