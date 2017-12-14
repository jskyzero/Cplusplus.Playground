/*

Copyright(R) Jskyzero

SYSU 2016/12/25

*/

#include <cassert>  // for assert()
#include <cctype>   // for isdigit()
#include <ciso646>  // for and or not bitand
#include <climits>  // for INT_MAX
#include <cmath>    // for cos() pow() sqrt() ceil() floor() fabs()
#include <cstdio>   // for fprintf(), fgetc(), fputs()
#include <cstdlib>  // for atoi() rand() malloc() free() qsort()
#include <cstring>  // for memset() strlen() strncpy() strncat() strncmp()
#include <ctime>    // for time() clock() asctime() gmtime() strftime()
#include <iostream>
#include <string>
#include <algorithm>
#include <list>

void basic_things(void);
void about_size(void);
void about_find(void);
void about_list(void);

int main() { basic_things(); }

void basic_things(void) { 
  about_size();
  // about_find();
  // about_list(); 
}

void about_size(void) {
  std::cout << "About Size" << std::endl
            << "MAX_INT : " << INT_MAX << std::endl
            << "1 MB    : " << pow(2, 20) / sizeof(int) << " * INT"
            << std::endl;
}

void about_find(void) {
  std::list<int> myList{5, 19, 34, 3, 33};

  auto it = std::find_if(myList.begin(), myList.end(), 
                  [&](const int v) { return 0 == (v % 17); });

  if (myList.end() == it) {
    std::cout << "item not found" << std::endl;
  } else {
    const int pos = std::distance(myList.begin(), it) + 1;
    std::cout << "item divisible by 17 found at position " << pos << std::endl;
  }
}

void about_list(void) {
  std::list<int> my_list;
  my_list.insert(my_list.end(), 1);
  std::cout << my_list.back();
} 