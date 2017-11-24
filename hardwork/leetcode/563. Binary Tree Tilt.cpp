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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int findTilt(TreeNode* root) {
    auto ans = 0;
    auto q = queue<TreeNode*>();
    update(root);
    q.push(root);

    while (not q.empty()) {
      auto left = 0;
      auto right = 0;
      auto top = q.front();
      q.pop();

      if (top != NULL) {
        if (top->left != NULL) {
          left = top->left->val;
          q.push(top->left);
        }

        if (top->right != NULL) {
          right = top->right->val;
          q.push(top->right);
        }
      }


      ans += abs(left - right);
    }
    return ans;
  }

  int update(TreeNode* root) {
    if (root == NULL) return 0;
    root->val += update(root->left) + update(root->right);
    return root->val;
  }
};