#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Date
{
public:
  Date(int newYear, int newMonth, int newDay)
  {
  	year = newYear;
	month = newMonth;
	day =  newDay;
   } 
  int getYear()
  {
  	return year;
  }
  void setYear(int newYear)
  {
  	year =  newYear;
  }


  int year;
  int month;
  int day;
};

class Person
{
public:
  Person(int id, int year, int month, int day);
  Person(Person &); // copy constructor
  ~Person();
  int getId();
  Date * getBirthDate();
  static int getNumberOfObjects(); //return the number of Person objects 
  int id;
  Date *birthDate; 
  static int numberOfObjects; //count the number of Person objects
};
int Person::numberOfObjects = 0;

Person::Person(int id, int year, int month, int day)
  {
  	this->id = id;
  	birthDate = new class Date(  year,  month,  day);
  	numberOfObjects += 1; 
  }
 Person::Person(Person & p ) // copy constructor
  {
  	this->id =  p.id;
  	this->birthDate = new Date(*( p.birthDate));
  	numberOfObjects += 1; 
   }  
 Person::~Person()
  {
   	numberOfObjects -= 1;
}
  
  
  int Person::getId()
  {
  	return id;
  }
  Date * Person::getBirthDate()
  {
  	return birthDate; 
  }
 int Person::getNumberOfObjects() //return the number of Person objects 
 {
 	return numberOfObjects;
 }
 
 int main() {
 	Person a(1,1,1,1);
	Person b(2,2,2,2);
	cout<<Person::getNumberOfObjects();
	 
	cout<<Person::getNumberOfObjects();
	return 0;
  }

