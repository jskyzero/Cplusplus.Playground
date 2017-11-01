#pragma once 
#include<iostream>
using namespace std;

class A
{
public:
	virtual void Prin()
	{
		cout<<"Prin come form class A"<<endl;
	}
	virtual ~A(){
	cout << "A::~A()called\n";	
	}
};                           

class B : public  A
{
   char *buf;
public:
    	void Prin()
	{
		cout<<"Prin come from class B"<<endl;
	}
	B(char ch = '\0'){
		buf = new char;
		*buf = ch;	
	}
	~B(){
		cout <<"B::~B()called\n";
	}
};

void fun(A *a)
{
	delete a;
}                          

int  main()
{	
	A *a = new B(10);
	a->Prin();
	fun(a);
	B *b =  new B(20);
	fun(b);
	return 0;
}                          




