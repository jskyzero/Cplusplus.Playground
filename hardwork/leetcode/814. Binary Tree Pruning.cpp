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
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a binary tree node.

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* pruneTree(TreeNode* root) {
    if (root == NULL) return NULL;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val == 0 && 
        root->left == NULL &&
        root->right == NULL) return NULL;
    return root;
  }
};