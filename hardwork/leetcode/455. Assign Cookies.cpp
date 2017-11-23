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
  int findContentChildren(vector<int>& g, vector<int>& s) {
    auto ans = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    for (auto need : g) {
      while (not s.empty() and s.front() < need) {
        s.erase(s.begin());
      }
      if (s.empty()) break;
      s.erase(s.begin());
      ans++;
    }
    return ans;
  }
};