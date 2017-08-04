#include<iostream>
#include<string> 
using namespace std;
void f()
 {
     string x, y, s;
     cout << "Please enter two strings\n";
     cin >> x >> y;
     cout << "x= " << x << " , y = " << y << '\n';

     cout << "s = \"" << s << "\"" << endl;
     s = "abc";
     cout << "s = \"" << s << "\"" << endl;

     cout << "\"" << x << "\" + \"" << y << "\" = " << "\"" << x+y << "\"\n";
     string z = x;
     if (x != z) cout << "x corrupted!\n";
     x[0] = '!';
     if (x == z) cout << "write failed!\n";
     cout << "exit: " << x << ' ' << z << '\n';    

     z = s;
     if (s != z) cout << "s corrupted!\n";
     s[0] = '!';
     if (s == z) cout << "write failed!\n";
     cout << "exit: " << s << ' ' << z << '\n';    
 }
int main(){
	f();
	return 0;
} 
