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
  int candy(vector<int>& ratings) {
    if (ratings.empty()) return 0;
    auto ans = 0;
    auto v = vector<int>(ratings.size());
    v[0] = 1;

    for (auto i = 1; i < ratings.size(); i++) {
      v[i] = ratings[i] > ratings[i - 1] ? v[i - 1] + 1 : 1;
    }

    ans += v.back();
    for (int i = ratings.size() - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1] and v[i] < v[i + 1] + 1)
        v[i] = v[i + 1] + 1;
      ans += v[i];
    }
    return ans;
  }
};