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
  vector<int> constructArray(int n, int k) {

    if ( n > k + 1 ) {
      auto ans = constructArray(k + 1, k);
      for (auto i = k + 2; i <= n; i++) {
        ans.push_back(i);
      }
      return ans;
    }
    else {
      auto ans = vector<int>{ 1 };
      auto table = vector<bool>(n);

      for (auto i = n - 1; i > 0; i--) {
        if (ans.back() + i <= n and not table[ans.back() + i]) {
          table[ans.back() + i] = true;
          ans.push_back(ans.back() + i);
        }
        else {
          table[ans.back() - i] = true;
          ans.push_back(ans.back() - i);
        }
      }
      return ans;
    }
  }
};