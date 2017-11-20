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
  TreeNode* convertBST(TreeNode* root) {
    auto q = queue<TreeNode *>();
    auto v = vector<int>();

    q.push(root);
    while (q.size() != 0) {
      auto top = q.front();
      if (top != NULL) {
        v.push_back(top->val);
        q.push(top->left);
        q.push(top->right);
      }
      q.pop();
    }

    updateBST(root, v);
    return root;
  }

  void updateBST(TreeNode* root, vector<int> &v) {
    if (root != NULL) {
      int add = 0;
      for (auto i : v) {
        add += i > root->val ? i : 0;
      }
      root->val += add;
      updateBST(root->left, v);
      updateBST(root->right, v);
    }
  }
};