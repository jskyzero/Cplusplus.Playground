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
#include <queue>
#include <vector>

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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> v;
    queue<decltype(root)> q;
    q.push(root);

    while(not q.empty()) {
      double ans = 0;
      auto size = q.size();
      for (auto i = 0; i < size; i++) {
        auto top = q.front();
        ans += top->val;
        if (top->left) q.push(top->left);
        if (top->right) q.push(top->right);
        q.pop();
      }
      v.push_back(ans/size);
    }
    return v;
  }
};