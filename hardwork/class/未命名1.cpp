
#include<cstring>
#include<string>
using namespace std;

class Stock
{
  public:
    Stock(string symbol, string name)
    {
    	symbol = symbol;
		name = name;
	}
    string getSymbol()
    { 
        return symbol;
    }
    string getName()
    {
        return name;
    }
    double getPreviousClosingPrice()
    { 
        return previousClosingPrice;
    }
    double getCurrentPrice()
    {
        return currentPrice;
    }
    void setPreviousClosingPrice(double previousClosingPrice)
    {
        previousClosingPrice = previousClosingPrice;
    }
    void setCurrentPrice(double currentPrice)
    {
        currentPrice = currentPrice;
    }
    double changePercent()
    {
        return currentPrice/previousClosingPrice;
    }
   private:
    string  symbol; 
    string name;
    double  previousClosingPrice;
    double  currentPrice;
  };                                
