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
  int longestPalindromeSubseq(string s) {
    if (s.empty()) return 0;

    vector<vector<int>> longest(s.size(), vector<int>(s.size()));
    for (int len = 1; len <= s.size(); len++) {
      for (int lhs = 0; lhs + len <= s.size(); lhs++) {
        int rhs = lhs + len - 1;
        if (lhs == rhs) {
          longest[lhs][rhs] = 1;
        } else if (lhs + 1 == rhs) {
          longest[lhs][rhs] = (s[lhs] == s[rhs]) ? 2 : 1;
        } else {
          int add = s[lhs] == s[rhs] ? 2 : 0;
          longest[lhs][rhs] =
              max(max(longest[lhs][rhs - 1], longest[lhs + 1][rhs]),
                  longest[lhs + 1][rhs - 1] + add);
        }
      }
    }

    return longest[0].back();
  }
};