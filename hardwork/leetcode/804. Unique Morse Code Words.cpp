/*
 * leetcode solution
 *
 * jskyzero
 *
 * */

// universal header file
#include <algorithm>
#include <cassert>
#include <ciso646>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  static constexpr int lower_char_to_index(char lower_char) {
    return lower_char - 'a';
  }
  int uniqueMorseRepresentations(vector<string>& words) {
    string table[] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                      "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                      "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                      "...-", ".--",  "-..-", "-.--", "--.."};
    auto string_set = set<string>();
    for (auto str : words) {
      auto temp = string("");
      for (auto c : str) {
        temp += table[lower_char_to_index(c)];
      }
      string_set.insert(temp);
    }
    return string_set.size();
  }
};