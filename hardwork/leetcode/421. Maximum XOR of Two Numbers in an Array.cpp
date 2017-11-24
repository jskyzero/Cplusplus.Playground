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
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    int max = 0, mask = 0;
    for (int i = 31; i >= 0; i--) {
      mask = mask | (1 << i);
      auto s = set<int>();
      for (int num : nums) {
        s.insert(num & mask);
      }
      int tmp = max | (1 << i);
      for (int prefix : s) {
        if (s.find(tmp ^ prefix) != s.end()) {
          max = tmp;
          break;
        }
      }
    }
    return max;
  }
};