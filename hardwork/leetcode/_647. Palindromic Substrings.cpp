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
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class Solution {
 public:
  int countSubstrings(string s) {
    int ans = 0;
    for (size_t i = 1; i <= s.size(); i++) {
      for (size_t j = i; j <= s.size(); j++) {
        if (isPalindromic(s.substr(j - i, i))) ans++;
      }
    }
    return ans;
  }

  bool isPalindromic(string str) {
    auto new_str = string(str);
    reverse(new_str.begin(), new_str.end());
    return str == new_str;
  }
};