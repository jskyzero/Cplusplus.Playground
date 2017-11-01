#include<iostream>
#include<string> 
using namespace std;
class String;
ostream& operator<<(ostream&, const String&);
istream& operator>>(istream&, String&);
class String {
 public:
     String() {this->str = "";}            // x = ""
     String(const char* p ) { this->str = p;}         // x = "abc" 
     String(const String& p) { this->str = p.str;}
     String& operator=(const char * p ) {this->str = p;return * this;}
     String& operator=(const String& p ){ this->str = p.str; return * this;}
     String operator+(String p) { String temp(*this); temp.str += p.str ;  return temp;}
     char& operator[](int i) { return this->str[i];}
     char operator[](int i) const{char ch = this->str[i]; return ch;}
     int size() const{ return this->str.size();}
     String& operator+=(const String & p ){ string temp = this->str; temp += p.str ; this->str = temp; return * this;}
     String& operator+=(const char* p ){ string temp = this->str; temp +=  p ; this->str = temp; return * this;}
     friend ostream& operator<<(ostream&, const String&);
     friend istream& operator>>(istream&, String&);
     friend bool operator==(const String& x, const char* s);
     friend bool operator==(const String& x, const String& y);
     friend bool operator!=(const String& x, const char* s);
     friend bool operator!=(const String& x, const String& y);
	string str;
 };
 
 ostream& operator<<(ostream& out, const String& p){
 	out << p.str;
 	return out;
 }
 istream& operator>>(istream& in , String& p){
 	in >> p.str;
 	return in;
 }
 bool operator==(const String& x, const char* s){
 	if(x.str == s) return 1;
 	else return 0;
 }
 bool operator==(const String& x, const String& y){
 	if(x.str == y.str) return 1;
 	else return 0;
 }
 bool operator!=(const String& x, const char* s){
 	if(x.str == s) return 0;
 	else return 1;
 }
 bool operator!=(const String& x, const String& y){
 	if(x.str == y.str) return 0;
 	else return 1;
 }
 
void f()
 {
     String x, y, s;
     cout << "Please enter two strings\n";
     cin >> x >> y;
     cout << "x= " << x << " , y = " << y << '\n';

     cout << "s = \"" << s << "\"" << endl;
     s = "abc";
     cout << "s = \"" << s << "\"" << endl;

     cout << "\"" << x << "\" + \"" << y << "\" = " << "\"" << x+y << "\"\n";
     String z = x;
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
 
 int main() {
 	f();
 	return 0;
 }
