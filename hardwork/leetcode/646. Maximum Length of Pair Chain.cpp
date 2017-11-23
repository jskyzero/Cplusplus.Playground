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
  int findLongestChain(vector<vector<int>>& pairs) {
    auto cmp = [](vector<int> left, vector<int> right) {
      return left.front() < right.front();
    };
    sort(pairs.begin(), pairs.end(), cmp);

    auto ans = 1;
    auto begin = pairs.front().front();
    auto next = pairs.front().back();

    for (auto pair : pairs) {
      cout << begin << " " << next << pair.front() << " " << pair.back() << endl;
      if (pair.front() >= begin and pair.back() < next) {
        begin = pair.front();
        next = pair.back();
      }
      else if (pair.front() > next) {
        ans++;
        begin = pair.front();
        next = pair.back();
      }
    }
    return ans;
  }
};