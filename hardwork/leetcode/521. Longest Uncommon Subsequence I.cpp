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
  int findLUSlength(string a, string b) {
    return a == b ? -1 : max(a.length(), b.length());
  }
};