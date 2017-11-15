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

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    if (bits.size() > 2) {
      if(bits[0] == 1) {
        // 10 or 11
        bits.erase(bits.begin());
        bits.erase(bits.begin());
        return isOneBitCharacter(bits);
      } else {
        // 0
        bits.erase(bits.begin());
        return isOneBitCharacter(bits);
      }
    } else if(bits.size() == 2) {
      return bits[0] != 1;
    } else {
      return true;
    }
  }
};