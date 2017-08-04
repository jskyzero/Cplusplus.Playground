#pragma once 
#include<iostream>
using namespace std;

class A
{	public :
   virtual void g()
   {
      fun();
   }
   A(){
   	cout << "A constructor\n";
   fun();
   }
  	virtual  ~A(){
   	cout << "A destructor\n";
   }
   virtual void fun() {
   	cout << "Call class A's fun\n";
   }
};
class B : public A
{	public :
	B(){
   	cout << "B constructor\n";
   }
   ~B(){
   	cout << "B destructor\n";
   }
   void g()
   {
      fun();
   }
   void fun() {
   	cout << "Call class B's fun\n";
   }
};
class C : public B 
{public :
	C(){
   	cout << "C constructor\n";
   }
   ~C(){
   	cout << "C destructor\n";
   }
   void g()
   {
      fun();
   }
   void fun() {
   	cout << "Call class C's fun\n";
   }
};

int main()
{  
	A *a=new C;
	a->g();
	delete a;
	return 0;
}
