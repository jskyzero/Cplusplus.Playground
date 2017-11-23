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
  int minMoves(vector<int>& nums) {
    auto minNum = nums.front();
    auto ans = 0;
    for (auto num : nums) {
      ans += num;
      minNum = min(minNum, num);
    }
    return ans - minNum * nums.size();
  }
};