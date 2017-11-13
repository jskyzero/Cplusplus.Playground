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
  vector<int> findDuplicates(vector<int>& nums) {
    auto size = nums.size();

    for (auto & num : nums) {
      auto times = (nums.at(num % size) - 1) / size;
      switch (times) {
        case 0:
        case 2:
          nums.at(num % size) += size;
          break;
        case 1:
        case 3:
          num += size * 2;
          break;
      }
    }

    auto ans = vector<int>();
    copy_if(nums.begin(), nums.end(), back_inserter(ans),
            [size](int i) { return i  > 2 * size; });

    for (auto& num : ans) {
      num = (num % size) ? (num % size) : size;
    }

    return ans;
  }
};

int main() {
  auto s = Solution();
  auto v = vector<int>{9,9,4,10,8,5,2,2,7,7};
  s.findDuplicates(v);
}