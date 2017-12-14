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
#include <sstream>
#include <stack>

typedef std::stack<char> Stack;
typedef std::string String;
typedef std::stringstream sstream;

#define is_right_parenthesis(ch) ((ch) == ')')
#define is_left_parenthesis(ch) ((ch) == '(')

int get_char_weight(const char ch) {
  int ans = 0;
  switch (ch) {
    case '+':
    case '-':
      ans = 1;
      break;
    case '*':
    case '/':
    case '%':
      ans = 2;
      break;
    case '(':
      ans = 3;
      break;
  }
  return ans;
}

bool is_lower_char(const char left, const char right) {
  return get_char_weight(right) > get_char_weight(left);
}

class Infix2Postfix {
 public:
  Infix2Postfix();
  void solve();
  friend std::istream &operator>>(std::istream &input, Infix2Postfix &my_obj);
  friend std::ostream &operator<<(std::ostream &output, Infix2Postfix &my_obj);

 private:
  Stack char_stack;
  String in;
  sstream out;
};

Infix2Postfix::Infix2Postfix() {}

void Infix2Postfix::solve() {
  for (auto &ch : in) {
    // 1）如果遇到操作数，我们就直接将其输出。
    if (isupper(ch) or islower(ch)) out << ch;
    // 3）如果遇到一个右括号，则将栈元素弹出，将弹出的操作符输出直到遇到左括号为止。注意，左括号只弹出并不输出。
    if (is_right_parenthesis(ch)) {
      while (not char_stack.empty() and
             not is_left_parenthesis(char_stack.top())) {
        out << char_stack.top();
        char_stack.pop();
      }
      char_stack.pop();
      continue;
    }
    // 2）如果遇到操作符，则我们将其放入到栈中，遇到左括号时我们也将其放入栈中。
    // 4）如果遇到任何其他的操作符，如（“+”，
    // “*”，“（”）等，从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止。弹出完这些元素后，才将遇到的操作符压入到栈中。有一点需要注意，只有在遇到"
    // ) "的情况下我们才弹出" ( "，其他情况我们都不会弹出" ( "。
    if (ispunct(ch)) {
      while (not char_stack.empty() and
             not is_lower_char(char_stack.top(), ch) and
             not is_left_parenthesis(char_stack.top())) {
        out << char_stack.top();
        char_stack.pop();
      }
      char_stack.push(ch);
    }
  }

  // 5）如果我们读到了输入的末尾，则将栈中所有元素依次弹出。
  while (!char_stack.empty()) {
    out << char_stack.top();
    char_stack.pop();
  }
}

std::istream &operator>>(std::istream &input, Infix2Postfix &my_obj) {
  input >> my_obj.in;
  return input;
}

std::ostream &operator<<(std::ostream &output, Infix2Postfix &my_obj) {
  my_obj.solve();
  output << my_obj.out.str();
  return output;
}

int main() {
  int n;
  std::cin >> n;

  while (n--) {
    Infix2Postfix my_obj;
    std::cin >> my_obj;
    std::cout << my_obj<<std::endl;
  }

  return 0;
}
