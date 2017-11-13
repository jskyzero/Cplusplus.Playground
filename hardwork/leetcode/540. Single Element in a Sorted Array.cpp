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
  int singleNonDuplicate(vector<int>& nums) {
    return singleNonDuplicate2(nums, 0, nums.size());
  }

  int singleNonDuplicate2(vector<int>& nums, int begin, int end) {
    int mid = (begin + end) / 2;
    int rightSingle = ((end - mid - 1) % 2 == 1) ? 1 : -1;
    if (mid - 1 >= begin) {
      // 1 1 2 
      if ((((nums.at(mid - 1) == nums.at(mid)) ? 1 : -1) * 
           rightSingle) > 0) {
        return singleNonDuplicate2(nums, rightSingle > 0 ? mid + 1 : mid, end);
      // 1 2 2
      } else {
        return singleNonDuplicate2(nums, begin, rightSingle > 0 ? mid : mid + 1);
      }
    } else {
      return nums.at(mid);
    }
  }
};