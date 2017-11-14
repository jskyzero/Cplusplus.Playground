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
  string optimalDivision(vector<int>& nums) {
    auto ans = to_string(nums[0]);
    nums.erase(nums.begin());
    if (nums.empty()) {
      return ans;
    } else if (nums.size() == 1) {
      return ans + "/" + to_string(nums[0]);
    } else {
      ans += "/(";
      for (auto num : nums) {
        ans += to_string(num);
        ans += "/";
      }
      ans.back() = ')';
      return ans;
    }
  }
};