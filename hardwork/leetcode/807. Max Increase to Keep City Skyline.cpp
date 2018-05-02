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

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        auto top_down = vector<int>(n, 0);
        auto left_right = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                top_down[i] = max(top_down[i], grid[i][j]);
                left_right[j] = max(left_right[j], grid[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += min(top_down[i], left_right[j]) - grid[i][j];
            }
        }
        return ans;
    }
};