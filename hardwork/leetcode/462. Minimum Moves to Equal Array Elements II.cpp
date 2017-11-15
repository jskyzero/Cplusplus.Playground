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
  int minMoves2(vector<int>& nums) {
    auto mid_size = nums.size() / 2;
    auto mid_it = nums.begin() + mid_size;
    nth_element(nums.begin(), mid_it, nums.end());
    auto mid = *mid_it;
    auto ans = 0;
    for (auto num : nums) {
      ans += abs(num - mid);
    }

    return ans;
  }
};