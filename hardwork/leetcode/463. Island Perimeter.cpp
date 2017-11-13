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
  int islandPerimeter(vector<vector<int>>& grid) {
    auto height = grid.size();
    auto width = grid.at(0).size();
    auto total = 0;
    auto twice = 0;

    for (auto i = 0; i < height; i++) {
      for (auto j = 0; j < width; j++) {
        if (1 == grid.at(i).at(j)) {
          total++;
          if (i - 1 >= 0) twice += grid.at(i - 1).at(j);
          if (i + 1 < height) twice += grid.at(i + 1).at(j);
          if (j - 1 >= 0) twice += grid.at(i).at(j - 1);
          if (j + 1 < width) twice += grid.at(i).at(j + 1);
        }
      }
    }
    return total * 4 - twice;
  }
};

// [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]