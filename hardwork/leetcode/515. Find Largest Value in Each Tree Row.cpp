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
  Ans(int val, int depth) : val(val), depth(depth) {}
};

class Solution {
 public:
  vector<int> largestValues(TreeNode *root) {
    if (root == NULL) {
      return vector<int>();
    } else {
      if (root->left == NULL and root->right == NULL) {
        auto v = vector<int>();
        v.insert(v.begin(), root->val);
        return v;
      } else if (root->left != NULL and root->right == NULL) {
        auto left = largestValues(root->left);
        left.insert(left.begin(), root->val);
        return left;
      } else if (root->left == NULL and root->right != NULL) {
        auto right = largestValues(root->right);
        right.insert(right.begin(), root->val);
        return right;
      } else {
        auto left = largestValues(root->left);
        auto right = largestValues(root->right);
        auto max_vec = left.size() > right.size() ? left : right;
        auto min_size = left.size() > right.size() ? right.size() : left.size();
        for (auto i = 0; i < min_size; i++) {
          max_vec[i] = left[i] > right[i] ? left[i] : right[i];
        }
        max_vec.insert(max_vec.begin(), root->val);
        return max_vec;
      }
    }
  }
};