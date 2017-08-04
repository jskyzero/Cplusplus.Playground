
#include <iostream>
#include <cmath>
#include <cstring>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;
#define NumLimit 1001 // 1 <= n < m <= 1000
#define PrimeLimit 10001 // 10 * 1000 + 1


int prime[PrimeLimit];
int number[1001];
int num[NumLimit];
int n, m, d, x;
long long y;
string str1;
string str2;

bool isPrime(int num)
{
    if(num == 1) return false;
       for(int i = 2; i < num; i++)
    {
      if(num % i == 0) return false;       
    } 
    return true;
}

void setPrime()
{
    for(int i = 2; i < 10001; i++)
       if(isPrime(i))
             prime[i] = 1;    
}



bool isValid(int row, int num)
{
    for(int i = 1; i < row; i++)
    {
        if(number[i] == num) 
           return false;
    }
    int sum = num;
    for(int i = row -  1; i >= 1 && i >= row - d + 1; i--)
    {
        sum += number[i];
        if(prime[sum]) return false;
    }
    return true;
}


bool dfs(int row)
{
	
    if(row == m - n + 2)
    {
    	str1 = "";
        for(int i = 1; i <= m - n + 1; i++)
        {
            str1+= to_string(number[i]);
			str1+=((i == m - n + 1)? "": ",");
        }
        
        return true;
    }
    
    for(int num = n; num <= m; num++)
    {
        number[row] = num;
        if(isValid(row, num) && dfs(row+1))
        {
            return true;
        }
    }
    return false;
}



bool isOK(int column, int number) {
	for(int i = n; i < column ; i++) {
		if(num[i] == number) return 0;
	}

	for(int i = column -1 ; i >= n && i >= column - x + 1 ; i--) {
	
		number += num[i];
		if(1 == prime[number]) {
			return 0;
		}
	}
	return 1;
}

bool DFS(int column) {
	str2 = "";
	if(column == m + 1) {
		for(int i = n; i <= m; i++) {
			str2+= to_string(num[i]);
			str2+=((i == m )? "": ",");
		}
		
		return 1;
	}
	for(int i = n; i <= m; i++) {

		num[column] = i;
		if(isOK(column, i) && DFS(column+1)) return 1;

	}
	return 0;
}

void temp( void ) {
	srand((unsigned)time(0));
	n = rand() % 1000;
    m = rand() % 1000;
    int max = (n > m ? n : m);
    n = (n < m ? n: m);
    m = max;
    while(1 == d || 0 == d) {
    	  d = rand() % 10;
	}
   x = d;
}
int main()
{
    setPrime();
    
    temp();
    while(n || m || d)
    {
    	y++;
        if(!dfs(1))str1 = "No anti-prime sequence exists.\n";
        if(!DFS(n))str2 = "No anti-prime sequence exists.\n";
        
        if(str1 != str2) {
        	cout << "n = " << n << endl
        		<<"m = " << m << endl
        		<<"x = " << x << endl
        		<<"str1 = " << str1 << endl
        		<<"str2 = " << str2 << endl;
        		break;
		}
		
        temp();
        cout << y << endl;
		
    }
  
    return 0;
}
