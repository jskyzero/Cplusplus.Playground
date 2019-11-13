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

class Solution {
 public:
  int oddCells(int n, int m, vector<vector<int>>& indices) {
    map<int, map<int, bool>> table;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        table[i][j] = false;
      }
    }

    for (auto index : indices) {
      for (int i = 0; i < m; i++) {
        table[index[0]][i] = !table[index[0]][i];
      }
      for (int i = 0; i < n; i++) {
        table[i][index[1]] = !table[i][index[1]];
      }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (table[i][j]) count++;
      }
    }
    return count;
  }
};