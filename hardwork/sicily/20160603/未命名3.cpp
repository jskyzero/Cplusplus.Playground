#include<iostream>
#include<string>
using namespace std;
//Design a class named Stock that contains:
class Stock {
	private:
// A string data field named symbol for the stock's symbol.
		string symbol;
		string name;
// A double data field named previousClosingPrice that stores the stock price for the previous day.
		double previousClosingPrice;
// A double data field named  currentPrice that stores the stock price for the current time.
		double currentPrice;
	public:
		// A constructor that creates a stock with specified symbol and name.
		Stock(string symbol, string name) {
			this->symbol = symbol;
			this->name = name;
		}
		// The accessor functions for all data fields.
		string getSymbol() {
			return 	this->symbol ;
		}
		string getName() {
			return this->name;
		}
		double getPreviousClosingPrice() {
			return this->previousClosingPrice;
		}
		double getCurrentPrice() {
			return this->currentPrice;
		}
		// The mutator functions for previousClosingPrice and currentPrice.
		void setPreviousClosingPrice(double previousClosingPrice) {
			this->previousClosingPrice = previousClosingPrice;
		}
		void setCurrentPrice(double currentPrice) {
			this->currentPrice = currentPrice;
		}
		// A function named changePercent() that returns the precentage changed from previousClosingPrice to currentPrice.
		double changePercent() {
			return (this->currentPrice / this->previousClosingPrice);
		}
};
