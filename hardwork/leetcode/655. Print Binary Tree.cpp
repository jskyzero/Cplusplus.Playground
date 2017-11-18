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
  vector<vector<string>> printTree(TreeNode* root) {
    int w = getWidth(root);
    int h = getHeight(root);
    
    auto ans = vector<vector<string>>(h, vector<string>(w));
    setValue(root, 0, 0, w - 1, ans);
    return ans;
  }

  int getWidth(TreeNode* root) {
    if (root == NULL) return 0;
    return max(getWidth(root->left), getWidth(root->right)) * 2 + 1;
  }

  int getHeight(TreeNode* root) {
    if (root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
  }

  void setValue(TreeNode * node, int h, int l, int r, vector<vector<string>> & v) {
    if (node != NULL) {
      auto w = (l + r) / 2;
      v[h][w] = to_string(node->val);
      setValue(node->left, h + 1, l, w - 1, v);
      setValue(node->right, h + 1, w + 1, r, v);
    }
  }
};