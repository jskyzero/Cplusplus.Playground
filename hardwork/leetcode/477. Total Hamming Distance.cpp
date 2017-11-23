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
#include <cmath>
#include <iostream>
#include <memory>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    auto ans = 0;
    auto finished = false;
    while (not finished) {
      auto isOn = 0;
      auto allZero = true;
      for (auto & num : nums) {
        allZero = allZero and (num == 0);
        isOn += num & 1;
        num = num >> 1;
      }
      finished = allZero;
      ans += isOn * (nums.size() - isOn);
    }
    return ans;
  }
};