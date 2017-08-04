#include<cstring>
#include<string>
using namespace std;

class Account {
	public :
		int id ;
		double balance ;
		double annualInterestRate ;
		Account()
		{
		 	id = 0;
			balance = 0;
			annualInterestRate = 0;	
		}
		double getMonthlyInterestRate()
		{
			return annualInterestRate / 12;
		}
		void withDraw( double n ) 
		{
			balance -= n;
		 } 
		 void deposit( double n )
		 {
		 	balance += n;
		 }
		 int getId() 
		 {
		 	return id;
		 }
		 double getBalance() 
		 {
		 	return balance;
		 }
		 void setId(int n)
		 {
		 	id = n;
		 }
		 void setBalance(double n)
		 {
		 	balance = n;
		 }
		 void setAnnualInterestRate(double n)
		 {
		 	annualInterestRate = n;
		 }
};
