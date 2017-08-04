#include <iostream>
using namespace std;

int DaysInMonth(  int mo, int yr );

class Date
{
public:
  Date(int y=0, int m=1, int d=1): year(y),month(m),day(d) {}  
  static bool leapyear(int yr) { if( ((yr % 4 == 0) && !(yr % 100 == 0)) || yr % 400 == 0 ) return 1; else return 0; }
  int getYear() const{return year;}
  int getMonth() const{return month;}
  int getDay() const{return day;}
  void Increment();
  void Decrement();
  friend ostream& operator<<(ostream&, const Date&);
  Date operator+(const int & a){
     	 Date temp(this->getYear(),this->getMonth(),this->getDay());
         temp.day += a;
         
          while(temp.getDay() > DaysInMonth(temp.getMonth(), temp.getYear())) {
        	temp.day = 1; temp.month++;
        	if (temp.getMonth() > 12) {	temp.month = 1; temp.year++;} }
		  while ( temp.getDay() <= 0 ) {
        	if( temp.getMonth() == 1 ) { 
             temp.day = 31;temp.month = 12;temp.year--;}
        	else{
    		 temp.month--;temp.day = DaysInMonth( temp.getMonth(),temp.getYear() );}}
         return temp;
     }
  Date operator-(const int & a){
         Date temp(this->getYear(),this->getMonth(),this->getDay());
         temp.day -= a;
         
          while(temp.getDay() > DaysInMonth(temp.getMonth(), temp.getYear())) {
        	temp.day = 1; temp.month++;
        	if (temp.getMonth() > 12) {	temp.month = 1; temp.year++;} }
		  while ( temp.getDay() <= 0 ) {
        	if( temp.getMonth() == 1 ) { 
             temp.day = 31;temp.month = 12;temp.year--;}
        	else{
    		 temp.month--;temp.day = DaysInMonth( temp.getMonth(),temp.getYear() );}}
         return temp;
     }
  Date& operator+=(const int & a){
         this->day += a;
         while(this->day > DaysInMonth(this->month, this->year)) {
        	this->day = 1; this->month++;
        	if (this->month > 12) {	this->month = 1; this->year++;} }
		  while ( this->day <= 0 ) {
        	if( this->month == 1 ) { 
             this->day = 31;this->month = 12;this->year--;}
        	else{
    		 this->month--;this->day = DaysInMonth( this->month,this->year );}}
         return *this;
     }
  Date& operator-=(const int & a){
         this->day -= a;
          while(this->day > DaysInMonth(this->month, this->year)) {
        	this->day = 1; this->month++;
        	if (this->month > 12) {	this->month = 1; this->year++;} }
		  while ( this->day <= 0 ) {
        	if( this->month == 1 ) { 
             this->day = 31;this->month = 12;this->year--;}
        	else{
    		 this->month--;this->day = DaysInMonth( this->month,this->year );}}
         return *this;
     }
private:
  int year;
  int month;
  int day;
  // add any member you need here  
};

void Date::Increment()
{
    day++;
    if (day > DaysInMonth(month, year))
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

void Date::Decrement()
{
    if ( day == 0 )
    {
        if( month == 1 )
        { 
             day = 31;
             month = 12;
             year--;
        }
        else
        {
             month--;
             day = DaysInMonth( month, year );
        }
    }	
}
ostream& operator << ( ostream& out, const Date& x)
{
	out << x.getYear() <<"-"
		<< x.getMonth() <<"-"
		<< x.getDay() <<endl;
	               

	return out;
}

int DaysInMonth(  int mo, int yr )
{
    switch (mo)
   {
     case 1: case 3: case 5: case 7: case 8: case 10: case 12:
              return 31;
     case 4: case 6: case 9: case 11:
             return 30;
     case 2:  
          if ((yr % 4 == 0 && yr % 100 != 0) ||yr % 400 == 0)
              return 29;
          else
              return 28;
    }
}

int main() {
  Date date(2004,2,28);

  cout << "date = " << date << endl;
  cout << "date+1 = " << date+1 << endl;
  cout << "date-1 = " << date-1 << endl;
  date+=366;
  cout << "date = " << date << endl;
  date-=365;
  cout << "date = " << date << endl;
  date-=-365;
  cout << "date = " << date << endl;
  date+=-366;
  cout << "date = " << date << endl;
      


  
      
  cout << endl;
}



