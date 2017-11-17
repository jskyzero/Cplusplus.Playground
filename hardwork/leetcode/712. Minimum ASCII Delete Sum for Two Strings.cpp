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
  int minimumDeleteSum(string s1, string s2) {
    auto v = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1));

    v[s1.size()][s2.size()] = 0;

    for (int i = s1.size() - 1; i >= 0; i--) {
      v[i][s2.size()] = v[i + 1][s2.size()] + s1[i];
    }
    for (int j = s2.size() - 1; j >= 0; j--) {
      v[s1.size()][j] = v[s1.size()][j + 1] + s2[j];
    }

    for (int i = s1.size() - 1; i >= 0; i--) {
      for (int j = s2.size() - 1; j >= 0; j--) {
        if (s1[i] == s2[j]) {
          v[i][j] = v[i + 1][j + 1];
        }
        else {
          v[i][j] = min(v[i + 1][j] + s1[i],
                        v[i][j + 1] + s2[j]);
        }
      }
    }

    //for (auto raw : v) {
    //  for (auto num : raw) {
    //    cout << num << " ";
    //  }
    //  cout << endl;
    //}

    return v[0][0];
  }
  //int minimumDeleteSum(string s1, string s2) {
  //  if (s1.empty()) {
  //    auto ans = 0;
  //    for (auto c : s2) {
  //      ans += c;
  //    }
  //    return ans;
  //  }
  //  if (s2.empty()) {
  //    auto ans = 0;
  //    for (auto c : s1) {
  //      ans += c;
  //    }
  //    return ans;
  //  }
  //  if (s1.front() == s2.front()) {
  //    s1.erase(s1.begin());
  //    s2.erase(s2.begin());
  //    return minimumDeleteSum(s1, s2);
  //  }
  //  else {
  //    auto left = string(s1.begin() + 1, s1.end());
  //    auto right = string(s2.begin() + 1, s2.end());
  //    return min(s1.front() + minimumDeleteSum(left, s2),
  //      s2.front() + minimumDeleteSum(s1, right));
  //  }
  //}
};