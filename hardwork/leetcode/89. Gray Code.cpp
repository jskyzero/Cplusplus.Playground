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
  vector<int> grayCode(int n) {
    if (n == 0) return vector<int>{0};
    if (n == 1) return vector<int>{0, 1};
    auto last = grayCode(n - 1);
    auto ans = vector<int>(last);
    for (auto i = last.rbegin(); i != last.rend(); i++) {
      ans.push_back( *i  + (1 << (n - 1)));
    }
    return ans;
  }
};