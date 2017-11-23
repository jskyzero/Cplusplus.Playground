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
  vector<int> nextGreaterElements(vector<int>& nums) {
    auto ans = vector<int>(nums.size(), -1);

    for (auto i = 0; i < nums.size(); i++) {
      auto it = find_if(nums.begin() + i, nums.end(),
        [i, &nums](auto n) {return n > nums[i]; });
      if (it == nums.end()) {
        auto it = find_if(nums.begin(), nums.begin() + i,
          [i, &nums](auto n) {return n > nums[i]; });
        if (it != nums.begin() + i) ans[i] = *it;
      }
      else {
        ans[i] = *it;
      }
    }
    return ans;
  }
};