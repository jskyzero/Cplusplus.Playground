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
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    auto ans = 0;
    auto m = map<int, int>();

    for (auto a : A) {
      for (auto b : B) {
        m[a + b]++;
      }
    }

    for (auto c : C) {
      for (auto d : D) {
        ans += (m[-c - d]);
      }
    }
    return ans;
  }

  // this one is more faster, why?
  //int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
  //  unordered_map<int, int>  abSum;
  //  for (auto a : A) {
  //    for (auto b : B) {
  //      ++abSum[a + b];
  //    }
  //  }
  //  int count = 0;
  //  for (auto c : C) {
  //    for (auto d : D) {
  //      auto it = abSum.find(0 - c - d);
  //      if (it != abSum.end()) {
  //        count += it->second;
  //      }
  //    }
  //  }
  //  return count;
  //}
};