#include <iostream> // allows program to perform input and output
using namespace std; // program uses names from the std namespace

int leapyear (int yr)
{
	
			if ((yr % 4 == 0) && !(yr % 100 == 0))
			cout<<yr;	
			else if (yr % 400 == 0)  // year divisible by 4 but not by 100
			cout<<yr;
			return yr;

}

int main()
{
	const int arraySize = 5; // arraySize must be const
	int year[ arraySize ]; // declare array for input

	cout << "Enter " << arraySize << " four digits years:\n";
	for ( int i = 0; i < arraySize; i++ )
    cin >> year[ i ];

	cout << leapyear(year)<<" is a leap year.\n" << endl;
	


  
} // end main 
