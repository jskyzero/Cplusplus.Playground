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

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    auto max = 0;

    for (auto i = 0; i < grid.size(); i++) {
      for (auto j = 0; j < grid.front().size(); j++) {
        if (grid[i][j] != 0) {
          auto eachArea = eachAreaOfPosition(grid, i, j);
          // cout << "ans = " << eachArea << " " << i << " " << j << endl;
          max = eachArea > max ? eachArea : max;
        }
      }
    }

    return max;
  }

  int eachAreaOfPosition(vector<vector<int>>& grid, int i, int j) {
    int ans = 1;
    grid[i][j] = 0;

    if (i - 1 >= 0 and grid[i - 1][j]) {
      ans += eachAreaOfPosition(grid, i - 1, j);
    }
    if (i + 1 < grid.size() and grid[i + 1][j]) {
      ans += eachAreaOfPosition(grid, i + 1, j);
    }
    if (j - 1 >= 0 and grid[i][j - 1]) {
      ans += eachAreaOfPosition(grid, i, j - 1);
    }
    if (j + 1 < grid.front().size() and grid[i][j + 1]) {
      ans += eachAreaOfPosition(grid, i, j + 1);
    }

    // cout << i << " " << j << " " << ans << endl;
    return ans;
  }
};