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
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
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
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
      auto node = new TreeNode(v);
      node->left = root;
      return node;
    }

    if (d == -1) {
      auto node = new TreeNode(v);
      node->right = root;
      return node;
    }

    if (root != NULL) {
      root->left = addOneRow(root->left, v, abs(d) - 1);
      root->right = addOneRow(root->right, v, -(abs(d) - 1));
    }
    return root;
  }
};