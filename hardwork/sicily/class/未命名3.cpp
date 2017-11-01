#include<iostream>
#include<string>

using namespace std;
class Stock
{
  public:
    Stock(string symbol, string name);
    string getSymbol()const;
    string getName();
    double getPreviousClosingPrice();
    double getCurrentPrice();
    void setPreviousClosingPrice(double previousClosingPrice);
    void setCurrentPrice(double currentPrice);
    double changePercent();
  private:
  	string Psymbol;
	string Pname;
	double PpreviousClosingPrice;
	double PcurrentPrice ; 
};

Stock::Stock(string symbol, string name)
{
	Psymbol = symbol;
	Pname = name;	
}
Stock::string getSymbol()const
{
	return Psymbol;
}
Stock::string getName()
{
	return Pname;
}
Stock::double getPreviousClosingPrice()
{
	return PpreviousClosingPrice;
}
Stock::double getCurrentPrice()
{
	return PcurrentPrice;
}
Stock::setPreviousClosingPrice(double previousClosingPrice)
{
	PpreviousClosingPrice = previousClosingPrice;
}
Stock:: setCurrentPrice(double currentPrice)
{
	PcurrentPrice = currentPrice;
}
Stock::double changePercent()
{
	return PcurrentPrice/PpreviousClosingPrice;
}
