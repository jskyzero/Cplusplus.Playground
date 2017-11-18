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
  vector<int> topKFrequent(vector<int>& nums, int k) {
    auto cmp = [](pair<int, int> const & left, pair<int, int> const & right) {
      return left.second > right.second;
    };

    auto m = map<int, int>();

    for (auto n : nums) {
      m[n]++;
    }

    auto v = vector<pair<int, int>>(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    auto ans = vector<int>();
    for (int i = 0; i < k; i++) {
      ans.push_back((v[i]).first);
    }

    return ans;
  }
};