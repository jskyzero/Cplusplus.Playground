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
  string frequencySort(string s) {
    auto cmp = [](pair<char, int> const & left, pair<char, int> const & right) {
      return left.second > right.second;
    };


    auto m = map<char, int>();
    for (auto c : s) {
      m[c]++;
    }

    auto v = vector<pair<char, int>>(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    string ans = "";
    for (auto i : v) {
      while (i.second--) {
        ans.push_back(i.first);
      }
    }

    return ans;
  }
};