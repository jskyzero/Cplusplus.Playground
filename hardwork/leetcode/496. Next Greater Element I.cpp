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
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    auto v = vector<int>();

    for (auto n : findNums) {
      auto index = find(nums.begin(), nums.end(), n);
      auto it = find_if(index, nums.end(), [n](auto x) { return x > n; });
      v.push_back(it == nums.end() ? -1 : *it);
    }

    return v;
  }
};