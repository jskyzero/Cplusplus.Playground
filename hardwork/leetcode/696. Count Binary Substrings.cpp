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
#include <unordered_map>
#include <vector>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class Solution {
 public:
  int countBinarySubstrings(string & s) {
    // 记录连续相等的数目
    auto v = vector<int>();
    auto count = 1;
    auto ans = 0;
    for (auto i = 1; i < s.size(); i ++) {
      if (s[i - 1] == s[i]) {
        count++;
      } else {
        v.push_back(count);
        count = 1;
      }
    }
      v.push_back(count);

    for (auto i = 1; i < v.size(); i++) {
      ans += min(v[i - 1], v[i]);
    }
    return ans;
  }
};