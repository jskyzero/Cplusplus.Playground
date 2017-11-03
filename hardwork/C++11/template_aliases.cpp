/*


In C++03, it is possible to define a typedef 
  only as a synonym for another type, 
  including a synonym for a template specialization
  with all actual template arguments specified. 
It is not possible to create a typedef template. 

C++11 adds this ability with this syntax:

*/


template <typename First, typename Second, int Third>
class SomeType{};

template <typename Second>
using TypedefName = SomeType<int, Second, 5>;

int main() {
  typedef void (*FunctionType)(double);  // Old style
  using FunctionType = void (*)(double); // New introduced syntax

}