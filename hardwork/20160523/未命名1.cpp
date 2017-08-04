// Problem#: 18359
// Submission#: 4724645
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 18359
// Submission#: 4724082
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<string>
#include<iomanip> 
#include<stdio.h>
using namespace std;

int main()
{
    long long n = 0;
    cin >> n;
    char ch;
    ch = getchar();
   int n0 = n;
    string temp ;
    while(n0) {
        ch = getchar();
        if(ch == '\n') n0--;
        if(n0<=0) break;
        temp += ch;
        }
    int N ;
    for(int i = 0 ; i < n ; i++){
    N = temp.find('*');
        cout << temp.substr(0,N)<<endl;
        temp.erase(0,N+1);
    }
    
    
    
    /* int N = temp.length();
    for(int i = N - 1 ; i >= 0; i--) {
        if('*' == temp[i]) temp[i] = '\0';
        else break;
    }
    for(int i = 0; i < N ;i++) {
        if('*' == temp[i]) cout << '\n';
        else 
        cout << temp[i];
    }
    */
    return 0;

}                                 
