class String {
 public:
     String();            // x = ""
     String(const char*);        // x = "abc" 
     String(const String&);    // x = other_string
     String& operator=(const char *);
     String& operator=(const String&);
     String operator+(String);
     char& operator[](int i);
     char operator[](int i) const;
     int size() const;
     String& operator+=(const String&);
     String& operator+=(const char*);
     friend ostream& operator<<(ostream&, const String&);
     friend istream& operator>>(istream&, String&);
     friend bool operator==(const String& x, const char* s);
     friend bool operator==(const String& x, const String& y);
     friend bool operator!=(const String& x, const char* s);
     friend bool operator!=(const String& x, const String& y);
 };
 The String class implemented may be used like this:
 int main() 
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
