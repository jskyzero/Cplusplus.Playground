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
#include <cmath>
#include <iostream>
#include <memory>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <stack>
#include <queue>
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
  int getMinimumDifference(TreeNode* root) {
    auto ans = INT_MAX;
    auto v = vector<int>();

    inTravel(root, v);

    auto last = v.front();
    v.erase(v.begin());
    for (auto now : v) {
      ans = min(abs(now - last), ans);
      last = now;
    }
    return ans;
  }

  void inTravel(TreeNode* root, vector<int> & v) {
    if (root == NULL) return ;
    inTravel(root->left, v);
    v.push_back(root->val);
    inTravel(root->right, v);
  } 
};