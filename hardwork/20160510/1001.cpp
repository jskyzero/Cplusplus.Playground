#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    Person(){ cout << "Construct Person" << endl;}
    ~Person(){ cout << "Destruct Person" << endl;}
public:
    string name;      //person¡¯s name	
	int sex;           //1--male, 0¡ªfemale
};

class Student : virtual public Person 
{
public:
	string sno;
	Student(){ cout << "Construct Student" << endl;}
    ~Student(){ cout << "Destruct Student" << endl;}
}; 
class Worker : virtual  public Person 
{
public:

	string wno;
	Worker(){ cout << "Construct Worker" << endl;}
    ~Worker(){ cout << "Destruct Worker" << endl;}
}; 
class InService : virtual public Student, virtual  public Worker
{
public:

	InService(){ cout << "Construct InService" << endl;}
    ~InService(){ cout << "Destruct InService" << endl;}
};
int main()
{
    InService is;
    is.name = "name";
    is.sex = 0;
    is.sno = "10390000";
    is.wno = "10990000";
    cout << ((Person*)(&is))->name << endl;
    cout << ((Person*)(&is))->sex << endl;
    cout << ((Student*)(&is))->sno << endl;
    cout << ((Worker*)(&is))->wno << endl;
    return 0;
}
