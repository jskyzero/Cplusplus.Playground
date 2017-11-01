#include<stdio.h>
bool sudoku(int g[9][9])

//returns true if it is a solution, otherwise returns false.

{
	char a[10] = {0};
	int ans = 1;
	for( int n = 1; n < 10; n++) {
		a[n] = 0;
	}
 //insert your code here.
 for(int i = 0; i < 9; i++) {
 	for( int n = 1; n < 10; n++) {
		a[n] = 0;
	}
 	for(int j = 0; j < 9; j++) {
 	 int _n = g[i][j]; 
		a[_n] = 1;
	 }
	 for( int n = 1; n < 10; n++) {
		ans *= a[n];
	}
}

 for(int i = 0; i < 9; i++) {
 	for( int n = 1; n < 10; n++) {
		a[n] = 0;
	}
 	for(int j = 0; j < 9; j++) {
 	 int _n = g[j][i]; 
		a[_n] = 1;
	 }
	 for( int n = 1; n < 10; n++) {
		ans *= a[n];
	}
}
int x, y;
for(x = 0; x <= 7; x+=3) {
	for(y = 0; y <= 7; y+=3) {
		for( int n = 1; n < 10; n++) {
		a[n] = 0;
	}
		for(int i = x; i < x + 3; i++) {
			
			for(int j = y; j < y+3; j++) {
			
				int _n = g[i][j]; 
				a[_n] = 1;
				
		}
	}
	for( int n = 1; n < 10; n++) {
		ans *= a[n];
	}
	}
	
}
return ans;
}

int main() {
	int a[9][9];
	int _n;
	for(int i = 0; i < 9; i++) {
 	
 	for(int j = 0; j < 9; j++) {
 		scanf("%d", &_n);	
 	 	a[i][j] =  _n; 
		
	 }
	 
}	
	printf("%d", sudoku(a));
	
	return 0;
}

