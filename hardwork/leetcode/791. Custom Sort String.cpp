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
  string customSortString(string S, string T) {
    auto comp = [&S](char left, char right) {
      auto left_weight = S.find_first_of(left);
      auto right_weight = S.find_first_of(right);
      return left_weight > right_weight;
    };

    sort(T.begin(), T.end(), comp);
    return T;
  }
};