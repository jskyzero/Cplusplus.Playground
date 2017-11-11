/*
 * leetcode solution
 *
 * jskyzero
 *
 * */

// universal header file
#include <algorithm>
#include <ciso646>
#include <cassert>
#include <iostream>
#include <memory>
#include <vector>
#include <set>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    auto s = set<int>(candies.begin(), candies.end());
    return min(s.size(), candies.size() / 2);

    // assert(candies.size() % 2 == 0);
    // int total_max = 0;

    // for (size_t i = 0; i < candies.size(); i+=2 ) {
    //   int pair_max = min(candies[i], candies[i+1]);
    //   total_max = max(pair_max, total_max);
    // }

    // return total_max;
  }
};