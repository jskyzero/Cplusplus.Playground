#include <iostream>
using namespace std;

class Date {
 public:
  Date(int newYear, int newMonth, int newDay);
  int getYear();
  void setYear(int newYear);

  int year;
  int month;
  int day;
};

class Person {
 public:
  Person(int id, int year, int month, int day);
  Person(Person &);  // copy constructor
  ~Person();
  int getId();
  Date *getBirthDate();
  static int getNumberOfObjects();  // return the number of Person objects

  int id;
  Date *birthDate;
  static int numberOfObjects;  // count the number of Person objects
};
Date::Date(int newYear, int newMonth, int newDay) {
  year = newYear;
  month = newMonth;
  day = newDay;
}
int Date::getYear() { return year; }
void Date::setYear(int newYear) { year = newYear; }
int Person::numberOfObjects = 0;
Person::Person(int id, int year, int month, int day) {
  this->id = id;
  this->birthDate = new Date(year, month, day);
  numberOfObjects++;
}
Person::Person(Person &p)  // copy constructor
{
  this->id = p.id;
  this->birthDate = new Date(*(p.birthDate));
  numberOfObjects++;
}
Person::~Person() { numberOfObjects--; }
int Person::getId() { return id; }
Date *Person::getBirthDate() { return birthDate; }
int Person::getNumberOfObjects() { return numberOfObjects; }
// return the number of Person objects
