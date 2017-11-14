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
  bool hasAlternatingBits(int n) {
    if (n < 2) return true;
    int last_two_bits_value = n % 4;
    if (last_two_bits_value == 1 or last_two_bits_value == 2) {
      return hasAlternatingBits(n >> 1);
    } else {
      return false;
    }
  }
};