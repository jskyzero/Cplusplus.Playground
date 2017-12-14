#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iomanip>
typedef std::map<char, double> Map; 
typedef std::pair<char, double> Pair;
typedef std::string String;

Map circuit;

double cal(String in) {
  std::string str = "";  
  str = str + in[0];  
  for (int i = 1; i < in.length(); ++i) {  
    if (isupper(str[str.length()-1]) &&  
         in[i] >= 'A' && in[i] <= 'Z') {  
      circuit[in[i]] *= circuit[str[str.length()-1]];  
      str[str.length()-1] = in[i];  
    } else {  
      str = str + in[i];  
    }  
  }  
  if (str.length() == 1)  
    return circuit[str[0]];  
  double temp = circuit[str[0]];  
  for (int i = 2; i < str.length(); i +=2)  
    temp = temp + circuit[str[i]] - temp*circuit[str[i]];  
  return temp; 
}

double solve(String in) {
  String mid, next;
  int begin = -1, end = -1, min_begin = 0, min_end = in.length() -1;
  char newchar;
  for (int i = 0; i < in.length(); i++) {
    if (in[i] == '(') {
      begin = i;
    } else if(in[i] == ')') {
      end = i;
      if (end - begin < min_end - min_begin) {
        min_begin = begin;
        min_end = end;
      }
    }  
  }
  if ( begin == -1 ) return cal(in);
  
  for( int i = min_begin + 1; i < min_end; i++) {
    mid = mid + in[i];
    if (isupper(in[i])) newchar = in[i];
  }

  // std::cout << " mid = " << mid;
  circuit[newchar] = solve(mid);
  for (int i = 0; i < min_begin; i++) next = next + in[i];
  next = next + newchar;
  for (int i = min_end + 1; i < in.length(); i++) next = next+ in[i];
  // std::cout << " next = " << next << std::endl;
  return solve(next); 
}

int main() {
  int nums;
  String in;  
  std::cin >> nums >> in;
  for (int i = 0; i < nums; i++) {
    double temp_value;
    std::cin >> temp_value;
    circuit.insert(Pair('A' + i, temp_value));
  }
  printf("%1.4lf\n", solve(in));
} 