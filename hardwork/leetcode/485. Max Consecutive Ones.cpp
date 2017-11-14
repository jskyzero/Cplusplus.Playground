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
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_times = 0;
    int now_times = 0;
    for (auto num : nums) {
      if (num == 1) {
        now_times++;
        max_times = now_times > max_times ? now_times : max_times;
      } else {
        now_times = 0;
      } 
    }
    return max_times;
  }
};