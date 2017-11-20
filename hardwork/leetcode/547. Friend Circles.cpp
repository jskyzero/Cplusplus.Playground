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


class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    for (int i = 0; i < M[0].size(); i++) {
      auto v = vector<int>();
      for (int j = 0; j < M.size(); j++) {
        //cout << i << " " << (M[j][i] == 1) << endl;
        if (M[j][i] == 1) v.push_back(j);
      }

      if (v.size() > 1) {
        auto newCircle = vector<int>(M[v[0]]);
        for (int j = 1; j < v.size(); j++) {
          for (int p = 0; p < newCircle.size(); p++) {
            newCircle[p] = M[v[j]][p] == 1 ? 1 : newCircle[p];
          }
        }
        for (auto n = v.rbegin(); n != v.rend(); n++) {
          M.erase(M.begin() + *n);
        }

        M.push_back(newCircle);
      }
    }
    return M.size();
  }
};