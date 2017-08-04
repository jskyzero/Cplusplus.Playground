#include <iostream>
#include<string>
#include<stdlib.h>

using namespace std;

class Object
{
	public:
	virtual ~Object() {}
				
};
 
class Animal:public Object
{
	public:
				
};
class Dog:public Animal
{
	public:
			
};
class Cat:public Animal
{
	public:
				
};
 
class Vehicle:public Object
{
	public:
				
};
class Bus:public Vehicle
{
	public:
				
};
class Car:public Vehicle
{
	public:
				
};
 
class Person:public Object
{
	public:
				
};
class Student:public Animal
{
	public:
				
};
class Teacher:public Animal
{
	public:
				
};

template<typename Base, typename T>
    inline bool Instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != NULL;
}
string instanceof(Object &n)
{
	Object * obj = &n;
	if(1 == Instanceof<Cat>(obj)) return "Cat";
	if(1 == Instanceof<Dog>(obj)) return "Dog";
	if(1 == Instanceof<Teacher>(obj)) return "Teacher";
	if(1 == Instanceof<Student>(obj)) return "Student";
	if(1 == Instanceof<Person>(obj)) return "Person";
	if(1 == Instanceof<Animal>(obj)) return "Animal";
	if(1 == Instanceof<Car>(obj)) return "Car";
	if(1 == Instanceof<Bus>(obj)) return "Bus";
	if(1 == Instanceof<Vehicle>(obj)) return "Vehicle";
	if(1 == Instanceof<Object>(obj)) return "Object";
	
}

int main() {
	{	
	Object *obj = new Dog();
	cout << instanceof(*obj) << endl;
	}
	
	Object *obj = new Car();
	cout << instanceof(*obj) << endl;
}
