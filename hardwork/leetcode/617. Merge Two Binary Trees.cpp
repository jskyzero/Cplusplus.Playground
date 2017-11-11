/*
 * leetcode solution
 *
 * jskyzero
 *
 * */

// universal header file
#include <ciso646>
#include <iostream>
#include <memory>
#include <algorithm>
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
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL and t2 == NULL) {
      return NULL;
    } else if (t1 == NULL) {
      auto root = new TreeNode(t2->val);
      root->left = mergeTrees(NULL, t2->left);
      root->right = mergeTrees(NULL, t2->right);
      return root;
    } else if (t2 == NULL) {
      auto root = new TreeNode(t1->val);
      root->left = mergeTrees(NULL, t1->left);
      root->right = mergeTrees(NULL, t1->right);
      return root;
    } else {
      auto root = new TreeNode(t1->val + t2->val);
      root->left = mergeTrees(t1->left, t2->left);
      root->right = mergeTrees(t1->right, t2->right);
      return root;
    }
  }
};