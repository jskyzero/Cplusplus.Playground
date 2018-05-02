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
  int numJewelsInStones(string J, string S) {
    uint8_t table[INT8_MAX] = {0};
    int ans = 0;

    for (auto c : J) { table[c] = 1; }
    auto check = [table](char c) { return table[c] == 1; };
    for (auto c : S) { ans += check(c) ? 1 : 0; }
    return ans;
  }
};