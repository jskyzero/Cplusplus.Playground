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
  int flipLights(int n, int m) {
    if (m == 0 || n == 0) return 1;
    if (n == 1) return 2;
    if (n == 2) return m == 1 ? 3 : 4;
    if (m == 1) return 4;
    return m == 2 ? 7 : 8;
  }
};
