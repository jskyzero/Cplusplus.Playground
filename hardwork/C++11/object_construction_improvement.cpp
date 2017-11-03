/*

C++11允许构造函数调用其他构造函数，这种做法称作委托或转接（delegation）

*/

#include <string>

class SomeType {
  int number;
  std::string name;
  SomeType( int i, std::string s ) : number(i), name(s){}
public:
  SomeType( )           : SomeType( 0, "invalid" ){}
  SomeType( int i )     : SomeType( i, "guest"){}
  SomeType( std::string& s ) : SomeType( 1, s ){ }
};

int main() {
  SomeType a{1};
  return 0;
}