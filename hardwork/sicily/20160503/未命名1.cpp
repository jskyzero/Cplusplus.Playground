// Problem#: 18361
// Submission#: 4723737
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<string>
#include<iomanip> 
using namespace std;
int main()
{
    long long n = 0;
    double N;
    cin >> n;
    while(n--) {
        cin >> N;
        ios_base::fmtflags t;
       
        cout.setf(t,ios_base::fixed);cout << N << endl;
         t = cout.setf(ios_base::fixed,ios_base::floatfield);cout <<N << endl;
}
    return 0;

}                                 
