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
  int findShortestSubArray(vector<int>& nums) {
    auto s = map<int, int>();
    auto begin = map<int, int>();
    auto end = map<int, int>();

    for (auto i = 0; i < nums.size(); i++) {
      if (s[nums[i]] == 0) {
        begin[nums[i]] = i;
      }

      s[nums[i]]++;
      end[nums[i]] = i;
    }

    auto ans = (int)nums.size();
    auto max_len = 0;
    for (auto pair : s) {
      if (pair.second == max_len) {
        ans = min(end[pair.first] - begin[pair.first] + 1, ans);
      }
      else if (pair.second > max_len) {
        ans = end[pair.first] - begin[pair.first] + 1;
        max_len = pair.second;
      }
    }
    return ans;
  }
};