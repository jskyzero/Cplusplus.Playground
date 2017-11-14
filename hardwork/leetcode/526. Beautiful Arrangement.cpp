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
  int countArrangement(int N) {
    auto n = N;
    auto v = vector<int>();

    for (auto i = 0; i < n; i++) {
      v.push_back(i + 1);
    }

    return countAllExchangeNth(N, v);
  }

  // int countAllExchangeNth(int n, vector<int>& v) {
  //   if (n == 0) return 1;
  //   int ans = 0;
  //   for (int i = 0; i < n; ++i) {
  //     if (v[i] % n == 0 || n % v[i] == 0) {
  //       swap(v[i], v[n - 1]);
  //       ans += countAllExchangeNth(n - 1, v);
  //       swap(v[i], v[n - 1]);
  //     }
  //   }
  //   return ans;
  // }

  int countAllExchangeNth(int n, vector<int>& v) {
    if (n == 0) return 1;
    int counts = 0;
    for (auto i = 0; i < n; i++) {
      if (v[i] % n == 0 or n % v[i] == 0) {
        swap(v[i], v[n - 1]);
        counts += countAllExchangeNth(n - 1, v);
        swap(v[i], v[n - 1]);
      }
    }
    return counts;
  }
};
