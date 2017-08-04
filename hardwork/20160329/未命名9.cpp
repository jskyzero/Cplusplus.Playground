#include <iostream>
using namespace std;

int DaysInMonth(  int mo, int yr ){
    switch (mo) {
     case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
     case 4: case 6: case 9: case 11: return 30;
     case 2:  if ((yr % 4 == 0 && yr % 100 != 0) ||yr % 400 == 0) return 29;
          	 else return 28;
    }
}

class Date
{
public:
  Date(int y=0, int m=1, int d=1): year(y),month(m),day(d) {} 
  static bool leapyear(int yr){ if( ((yr % 4 == 0) && !(yr % 100 == 0)) || yr % 400 == 0 ) return 1; else return 0; }
  int getYear() const{return year;}
  int getMonth() const{return month;}
  int getDay() const{return day;}
  
  void check() {
  	 while(this->day > DaysInMonth(this->month, this->year)) {
        	this->day -= DaysInMonth(this->month, this->year); this->month++;
        	if (this->month > 12) {	this->month = 1; this->year++;} }
		  while ( this->day <= 0 ) {
        	if( this->month == 1 ) { 
             this->day += 31;this->month = 12;this->year--;}
        	else{
    		 this->month--;this->day += DaysInMonth( this->month,this->year );}}
	}
  
  Date operator+(const int & a){
     	 Date temp(this->getYear(),this->getMonth(),this->getDay());
         temp.day += a;
         temp.check();
         return temp;
     }
  Date operator-(const int & a){
         Date temp(this->getYear(),this->getMonth(),this->getDay());
         temp.day -= a;
         temp.check();
         return temp;
     }
  Date& operator+=(const int & a){
         this->day += a;
         this->check();
         return *this;
     }
  Date& operator-=(const int & a){
         this->day -= a;
         this->check();  
         return *this;
     }
	Date & operator++() {this->day += 1; this->check();; return *this ;}     
	Date operator++(int){Date temp(this->getYear(),this->getMonth(),this->getDay()); this->day += 1; this->check(); return temp;};   
	Date & operator--(){this->day -= 1; this->check();; return *this ;}   
	Date operator--(int){Date temp(this->getYear(),this->getMonth(),this->getDay()); this->day -= 1; this->check(); return temp;};  	
	
	int operator<(const Date &a) {	if(this->getYear() < a.getYear()) return 1; 
	else if((this->getYear() == a.getYear())&&(this->getMonth() < a.getMonth())) return 1; 
	else if((this->getYear() == a.getYear())&&(this->getMonth()==a.getMonth())&&(this->getDay() < a.getDay()))return 1;
	else return 0;}
	int operator>(const Date &a) {	if(this->getYear() > a.getYear()) return 1; 
	else if((this->getYear() == a.getYear())&&(this->getMonth() > a.getMonth())) return 1;
	else if((this->getYear() == a.getYear())&&(this->getMonth()==a.getMonth())&&(this->getDay() > a.getDay()))return 1;
	else return 0;}
	int operator<=(const Date &a) {	if(this->getYear() <= a.getYear()) return 1; 
	else if((this->getYear() == a.getYear())&&(this->getMonth() <= a.getMonth())) return 1; 
	else if((this->getYear() == a.getYear())&&(this->getMonth()==a.getMonth())&&(this->getDay() <= a.getDay()))return 1;
	else return 0;}
	int operator>=(const Date &a) {	if(this->getYear() >= a.getYear()) return 1; 
	else if((this->getYear() == a.getYear())&&(this->getMonth() >= a.getMonth())) return 1; 
	else if((this->getYear() == a.getYear())&&(this->getMonth()==a.getMonth())&&(this->getDay() >= a.getDay()))return 1;
	else return 0;}
	int operator==(const Date &a){if(((this->getYear() == a.getYear())&&(this->getMonth()==a.getMonth()))&&(this->getDay() == a.getDay()))return 1;
	else return 0;} 
	int operator!=(const Date &a) {if(((this->getYear() == a.getYear())&&(this->getMonth()==a.getMonth()))&&(this->getDay() == a.getDay()))return 0;
	else return 1;} 
	
	
  friend ostream& operator<<(ostream&, const Date&);
  int&operator[](string str) {
  		int n = 0;
		if(str == "year") return n = this->getYear();
		if(str == "month")return  n = this->getMonth();
		if(str == "day") return n = this->getDay();
		else return n;
	}
  
private:
  int year;
  int month;
  int day;
};
void f1()
{
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
void f2()
{
  Date date(2004,2,28);
  cout << "date = " << date << endl;
  cout << "++date = " << ++date << endl;
  cout << "--date = " << --date << endl;
  cout << "date++ = " << date++ << endl;
  cout << "date-- = " << date-- << endl;
  cout << "date = " << date << endl;
}

void f3()
{
  Date date1, date2(2003,1,1);
  Date date3 = Date(2007,2,28);
  date3 = date1;

  cout << "year 1996 is leap year? " << Date::leapyear(1996) << endl;
  cout << "year 1200 is leap year? " << Date::leapyear(1200) << endl;
  cout << "year 1300 is leap year? " << Date::leapyear(1300) << endl;
  cout << "year 1999 is leap year? " << Date::leapyear(1999) << endl;

  cout <<  "(date1==date3)? " << (date1==date3) << endl;
  cout <<  "(date1!=date3)? " << (date1!=date3) << endl;
  cout <<  "(date1==date2)? " << (date1==date2) << endl;
  cout <<  "(date1!=date2)? " << (date1!=date2) << endl;

  cout <<  "(date1<date1)? " << (date1<date1) << endl;
  cout <<  "(date1<=date1)? " << (date1<=date1) << endl;
  cout <<  "(date1<date2)? " << (date1<date2) << endl;
  cout <<  "(date1<=date2)? " << (date1<=date2) << endl;
 
  cout <<  "(date1>date1)? " << (date1>date1) << endl;
  cout <<  "(date1>=date1)? " << (date1>=date1) << endl;
  cout <<  "(date1>date2)? " << (date1>date2) << endl;
  cout <<  "(date1>=date2)? " << (date1>=date2) << endl;
}

ostream& operator << ( ostream& out, const Date& x)
{
	out << x.getYear() <<"-"
		<< x.getMonth() <<"-"
		<< x.getDay() <<endl;
	return out;
}


int main() {
  f1();
  f2();
  f3();
  Date a(2016,3,28);
  cout  << a["year"]
  		<< a["month"]
		<< a["day"];    


  
      
  cout << endl;
}

