#include<iostream>
#include<string>
using namespace std;

#include<cctype>
char  maxValue (const char value1, const char value2)
{
		char ch1 = toupper(value1);
 		char ch2 = toupper(value2);
	 return(ch1 >= ch2 ? value1:value2 );
}
template < typename T >
 T maxValue (const T value1, const T value2)
 {	
	 return(value1 >= value2?  value1:value2);
 }
 
 int main()
 {
 	cout<<maxValue(2,3)<<endl;
 	 	cout<<maxValue('a','b')<<endl;
 	 	 	cout<<maxValue("abc","bcd")<<endl;
 }
 
