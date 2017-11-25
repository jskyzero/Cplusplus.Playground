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
    vector<string> findRelativeRanks(vector<int>& nums) {
        auto rank = decltype(nums)(nums);
        auto ans = vector<string>(nums.size());
        auto cmp = [](int left, int right)->bool {
          return left > right;
        };
        sort(rank.begin(), rank.end(), cmp);

        for (auto i = 0; i < nums.size(); i++) {
          auto num = nums[i];
          num = find(rank.begin(), rank.end(), num) - rank.begin();
          if (num == 0) ans[i] = "Gold Medal";
          else if (num == 1) ans[i] = "Silver Medal";
          else if (num == 2) ans[i] = "Bronze Medal";
          else ans[i] = to_string(num + 1);
        }

        return ans;
    }
};