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
  vector<int> findFrequentTreeSum(TreeNode *root) {
    if (root == NULL) return vector<int>();
    function<bool(int, int)> comp = [](int left, int right) {
      return left > right;
    };

    auto m = map<int, int, decltype(comp)>(comp);

    findFrequentTreeSumByMap(root, m);

    // for (auto i : m) {
    //   cout << i.first << " " << i.second << endl;
    // }

    auto ans = vector<int>();
    auto max = m.begin()->second;

    for (auto x : m) {
      if (x.second > max)
        max = x.second;
    }

    for (auto x : m) {
      if (x.second == max)
        ans.push_back(x.first);
    }
    return ans;
  }

  int findFrequentTreeSumByMap(TreeNode *root,
                               map<int, int, function<bool(int, int)>> &m) {
    if (root->left == NULL and root->right == NULL) {
      m[root->val] += 1;
      return root->val;
    } else if (root->left != NULL and root->right == NULL) {
      auto left = findFrequentTreeSumByMap(root->left, m);
      m[root->val + left] += 1;
      return root->val + left;
    } else if (root->left == NULL and root->right != NULL) {
      auto right = findFrequentTreeSumByMap(root->right, m);
      m[root->val + right] += 1;
      return root->val + right;
    } else if (root->left != NULL and root->right != NULL) {
      auto left = findFrequentTreeSumByMap(root->left, m);
      auto right = findFrequentTreeSumByMap(root->right, m);
      m[root->val + right + left] += 1;
      return root->val + right + left;
    }
  }
};