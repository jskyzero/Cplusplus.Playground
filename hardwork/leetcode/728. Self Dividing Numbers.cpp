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
#include <string>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {
    auto ans = vector<int>();
    for (auto i = left; i <= right; i++) {
      if (isSelfDividingNumber(i))
        ans.push_back(i);
    }
    return ans;
  }

  bool isSelfDividingNumber(int num) {
    auto isOk = true;
    auto str = to_string(num);
    for (auto c : str) {
      if (c == '0')
        isOk = false;
      else
        isOk &= (num % (c - '0') == 0);
    }
    return isOk;
  }
};