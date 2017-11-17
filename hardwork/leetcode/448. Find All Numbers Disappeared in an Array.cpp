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
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    auto table = vector<bool>(nums.size() + 1);
    auto ans = vector<int>();

    for (auto n : nums) {
      table[n] = true;
    }

    for (int i = 1; i < table.size(); i++) {
      if (not table[i]) ans.push_back(i);
    }

    return ans;
  }
};