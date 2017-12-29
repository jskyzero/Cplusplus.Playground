/*

this code can be compiled both in C and C++

I just want to test the sizeof :)  

*/
#include <stdio.h>

int main() {
	int a[10];
	printf("%d",  (sizeof(a) == sizeof(int) * 10));
	int* p = a;
	printf("%d\n", (sizeof(p) == sizeof(&a)));
	
	return 0;
}
