#include<iostream>
#include<string>
using namespace std;

class TypeA
 {
 public:
   class SubType
   {
   public:
     string toString() {return "subType in TypeA";};
   };
 };

 class TypeB
 {
 public:
   class SubType
   {
   public:
     string toString() {return "subType in TypeB";};
   };
 };
template <class T>
 class MyClass
 {
 public:
 
 	 class T::SubType subtypeobj;
 //add your public member here
 };
 
 int main()
 {
 MyClass<TypeA> obj1;
 cout << obj1.subtypeobj.toString() << endl;
 MyClass<TypeB> obj2;
 cout << obj2.subtypeobj.toString() << endl;
 }
 
