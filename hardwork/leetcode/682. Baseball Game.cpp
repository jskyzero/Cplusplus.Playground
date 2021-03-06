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
  int calPoints(vector<string>& ops) {
    auto ans = stack<int>();
    for (auto op : ops) {
      if (op == "C") {
        ans.pop();
      } else if (op == "D") {
        ans.push(ans.top() * 2);
      } else if (op == "+") {
        auto last1 = ans.top();
        ans.pop();
        auto last2 = ans.top();
        ans.push(last1);
        ans.push(last2 + last1);
      } else {
        ans.push(atoi(op.c_str()));
      }
    }
    // return accumulate(ans.begin(), ans.end(), 0);
    int sum = 0;
    while(not ans.empty()) {
        sum += ans.top();
        ans.pop();
    }
    return sum;
    }
  }
};