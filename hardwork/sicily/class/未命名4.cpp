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

private:
  int year;
  int month;
  int day;
};

class Person
{
public:
  Person(int id, int year, int month, int day)
  {
  	id = id;
  	birthDate = new class Date(  year,  month,  day);
  	numberOfObjects += 1; 
  }
  Person(Person & p ) // copy constructor
  {
  	id =  p.id;
  	birthDate =  p.birthDate;
  	numberOfObjects +=1; 
   }  
  ~Person()
  {
  	numberOfObjects = 0;
  }
  int getId()
  {
  	return id;
  }
  Date * getBirthDate()
  {
  	return birthDate; 
  }
  static int getNumberOfObjects() //return the number of Person objects 
 {
 	return numberOfObjects;
 }
private:
  int id;
  Date *birthDate; 
  static int numberOfObjects; //count the number of Person objects
};
