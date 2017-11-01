#include<iostream>
#include<string>
#include<cstring>
using namespace std;
// With a class "Student" declared as below:
class Student {

	public:
		int id;
		char name[50]; // Data field
		int age; // Data field
		Student();
		Student(int, char*, int);
};

// You are required to implement the class functions and also two other functions used to process Student objects, which can get output as specified later.
Student::Student() {
	id = 0;
	strcpy(name,"No Name");
	age = 0;
}
Student::Student(int id , char* p = "No Name", int age = 0) {
	this->id = id;
	strcpy(name,p);
	this->age = age;
}
void set(Student &s ,int id , char* p , int age ) {
	s.id = id;
	s.age = age;
	strcpy(s.name,p);
}
void print(Student s) {
	cout<<s.name<<"("<<s.id<<") is "<<s.age<<" years old."<<endl;
}

// 1) You don't need to submit the main function.

// 2) You don't need to include the header file for class declaration by yourself.


int main() {

	Student std1, std2(123, "John Smith", 18), std3(124);
	set(std1, 100, "Bill Gates", 61);
	print(std1);
	print(std2);
	print(std3);
	return 0;
}
