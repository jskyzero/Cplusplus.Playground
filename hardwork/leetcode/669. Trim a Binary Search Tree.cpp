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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (root != NULL) {
      if (root->val < L) {
        return trimBST(root->right, L, R);
      } else if (root->val > R) {
        return trimBST(root->left, L, R);
      } else if (root->val >= L and root->val <= R) {
        auto node = new TreeNode(root->val);
        node->left = trimBST(root->left, L, R);
        node->right = trimBST(root->right, L, R);
        return node;
      } else {
        return NULL;
      }
    } else {
      return NULL;
    }
  }
};