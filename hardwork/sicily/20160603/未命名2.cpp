

#include<iostream>

using namespace std;

class Account {
	private:
		int id;
		double balance;
		double annualInterestRate;
	public:
		Account() {
			this->id = 0;
			this->balance = 0;
			this->annualInterestRate = 0;
		}
		Account(int id,
		        double balance,
		        double annualInterestRate) {
			this->id = id;
			this->balance = balance;
			this->annualInterestRate = annualInterestRate;
		}
		int getId() {
			return this->id;
		}
		double getBalance() {
			return this->balance;
		}
		double getAnnualInterestRate() {
			return this->annualInterestRate;
		}
		void setId(int id) {
			this->id = id;
		}
		void setBalance(double balance) {
			this->balance = balance;
		}
		void setAnnualInterestRate(double annualInterestRate) {
			this->annualInterestRate = annualInterestRate;
		}
		double  getMonthlyInterestRate() {
			return (this->annualInterestRate / 12);
		}

		void withDraw(double balance) {
			this->balance -= balance;
		}
		void deposits(double balance) {
			this->balance += balance;
		}

};
