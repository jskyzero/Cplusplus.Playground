#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <ciso646>
#include <cassert>

typedef std::list<int> List;
typedef std::string String;

bool is_left(char ch) {
  return ch == '(' or ch == '{' or ch == '[';
}

bool is_right(char ch) {
  return ch == ')' or ch == '}' or ch == ']';
}

char to_left(char ch) {
  switch(ch) {
    case ')':
      return '('; 
    case '}': 
      return '{';
    case ']':
      return '[';
  }
  return '\0';
}

void bracket_matching() {
  String line_str;
  List bracket_stack;
  bool not_ok = false;
  std::cin >>  line_str;
  for (auto & each_char : line_str) {
    if (is_left(each_char)) bracket_stack.push_back(each_char);
    if (is_right(each_char)) {

      if (not bracket_stack.empty() and bracket_stack.back() == to_left(each_char)) {
        bracket_stack.pop_back();
      } else {
        not_ok = true;
        break;
      }
    }
  }

  if (not_ok or not bracket_stack.empty()) {
    std::cout << "No" << std::endl;
  } else {
    std::cout << "Yes" << std::endl;
  }
}

int main() {
  assert(is_left('('));
  assert(is_left('['));
  assert(is_left('{'));
  assert(is_right(')'));
  assert(is_right('}'));
  assert(is_right(']'));
  int times;
  std::cin >> times;
  while(times--) {
    bracket_matching();
  }
}