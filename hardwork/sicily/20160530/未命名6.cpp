#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include<typeinfo.h>

using namespace std;


template< typename T >
bool cmp( T * a, T * b ){
	 return (*a == *b);
	
}

bool cmp( char*  a, char*   b ){
	if(0 == strcmp(a,b)) return 1;
	else return 0;
}
bool cmp( int  a, int    b ){
	return (a == b);
}
bool cmp( double a, double   b ){
	return (a == b);
}
bool cmp( float  a, float   b ){
	return (a == b);
}
bool cmp( string  a, string  b ){
	return (a == b);
}


int main() {
	 int aInt = 1, bInt = 2 ;
 double aDouble = 3.0, bDouble = 3.0 ;
 char aChars[5] = "haha", bChars[5] ;
 string aStr = "haha", bStr = "aha" ;
 int* aIntPtr = &aInt, *bIntPtr = &bInt ;

 cout << boolalpha << cmp( aInt, bInt ) << endl ;
 cout << cmp( aDouble, bDouble ) << endl ;

 strcpy( bChars, aChars ) ;
 cout << bChars<< endl ;
 cout <<  aChars<< endl ;
 cout << strcmp(aChars,bChars)<< endl ;
 cout << cmp( aChars, bChars ) << endl ;
 cout << cmp( aStr, bStr ) << endl ;
 cout << cmp( aIntPtr, bIntPtr ) << endl ;
}
