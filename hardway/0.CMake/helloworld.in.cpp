#include <iostream>

#define USE_SOME_LIB True

#ifdef USE_SOME_LIB
#include <somefunction.hpp>
#endif

using namespace std;

#define MESSAGE "@MESSAGE@"

int main() {

#ifdef USE_SOME_LIB
  cout << MESSAGE << endl;
  printSomeThings();
#endif

  return 0;
}