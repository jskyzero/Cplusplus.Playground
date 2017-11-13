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
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Ans {
  int val;
  int depth;
  Ans(int val, int depth): val(val), depth(depth) {}
};

class Solution {
 public:
  int findBottomLeftValue(TreeNode *root) {
    return findBottomLeftValue2(root).val;
  }

  Ans findBottomLeftValue2(TreeNode *root) {
    if (root->left == NULL and root->right == NULL) {
      return  Ans(root->val, 0);
    } else if (root->left == NULL and root->right != NULL) {
      auto right = findBottomLeftValue2(root->right);
      right.depth += 1;
      return right;
    } else if (root->left != NULL and root->right == NULL) {
      auto left = findBottomLeftValue2(root->left);
      left.depth += 1;
      return left;
    } else {
      auto left = findBottomLeftValue2(root->left);
      auto right = findBottomLeftValue2(root->right);
      right.depth += 1;
      left.depth += 1;
      auto depth = max(left.depth, right.depth);
      return Ans(left.depth < right.depth ? right.val : left.val, depth);
    }
  }
};