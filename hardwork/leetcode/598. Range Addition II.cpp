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
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    auto ans = vector<int> { m, n };
    for (auto each : ops) {
      // such easy ?
      if (each[0] < ans[0] and each[1] < ans[1]) {
        ans = decltype(each)(each);
      } else if (each[0] < ans[0]) {
        ans[0] = each[0];
      } else if (each[1] < ans[1]) {
        ans[1] = each[1];
      }
    }
    return ans[0] * ans[1];
  }
};