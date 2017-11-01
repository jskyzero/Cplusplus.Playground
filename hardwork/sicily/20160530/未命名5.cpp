#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include<typeinfo.h>

using namespace std;


template< typename T >
bool cmp( T a, T b ){
	string temp = typeid(a).name();
	cout << temp << endl;
	if('P' != temp[0]) return (a == b);
	else 1;
}

bool cmp( char*  a, char*   b ){
	return strcmp(a,b);
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
 cout << cmp( aChars, bChars ) << endl ;
 cout << cmp( aStr, bStr ) << endl ;
 cout << cmp( aIntPtr, bIntPtr ) << endl ;
}
