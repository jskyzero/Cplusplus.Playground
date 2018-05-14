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
  vector<int> numberOfLines(vector<int>& widths, string S) {
    auto result = vector<int>{0, 0};
    for (auto c : S) {
      auto index = c - 'a';
      auto width = widths[index];
      result[1] += width;
      if (result[1] > 100) {
        result[0]++;
        result[1] = width;
      }
    }
    if (result[1] > 0) result[0]++;
    return result;
  }
};