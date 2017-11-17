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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    return findTargetBy(root, root, k);
  }

  bool findTargetBy(TreeNode* root, TreeNode* now, int k) {
    if (now == NULL) return false;
    auto p = findNode(root, k - now->val);
    if (p != NULL) {
      if (p == now) {
        if (findNode(now->right, k - now->val) != NULL)
          return true;
      }
      else return true;
    }
    if (findTargetBy(root, now->left, k)) return true;
    if (findTargetBy(root, now->right, k)) return true;
    return false;
  }

  TreeNode* findNode(TreeNode* root, int value) {
    if (root == NULL) return NULL;
    if (root->val == value) {
      return root;
    }
    else if (root->val < value) {
      return findNode(root->right, value);
    }
    else {
      return findNode(root->left, value);
    }
  }
};