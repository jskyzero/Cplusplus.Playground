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
  vector<int> constructRectangle(int area) {
    for (auto i = (int)floor(sqrt((double)area)); i > 1; i--) {
      if (area % i == 0)
        return vector<decltype(area)> {area / i, i};
    }
    return vector<decltype(area)> {area, 1};
  }
};