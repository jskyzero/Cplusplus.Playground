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
   vector<string> generateParenthesis(int n) {
    auto ans = vector<string>();
    make(ans,"", n, 0);
    return ans;
   }

   void make(vector<string> & v, string str, int n, int m) {
     if (n == 0 and m == 0) {
        v.push_back(str);
        return;
     }
     if (n > 0) make(v, str+'(', n - 1, m + 1);
     if (m > 0) make(v, str+')', n, m - 1);
   }

  // vector<string> generateParenthesis(int n) {
  //   if (n == 0) return vector<string>{""};
  //   if (n == 1) return vector<string>{"()"};

  //   auto v = generateParenthesis(n - 1);
  //   auto ans = vector<string>();

  //   for (auto i = 0; i < v.size(); i++) {
  //     ans.push_back("(" + v[i] + ")");
  //   }

  //   for (auto i = 0; i < v.size(); i++) {
  //     if ("()" + v[i] != v[i] + "()") 
  //       ans.push_back(v[i] + "()");
  //     ans.push_back("()" + v[i]);
  //   }
  //   return ans;
  // }
};