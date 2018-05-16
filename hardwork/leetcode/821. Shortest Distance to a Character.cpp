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
  vector<int> shortestToChar(string S, char C) {
    auto result = vector<int>{};

    for (auto i = 0; i < S.size(); i++ ) {
      if (S[i] == C) {
        result.push_back(0);
      } else {
        auto left = S.substr(0, i).find_last_of(C) == string::npos ? 
                    INT_MAX : i - S.substr(0, i).find_last_of(C);
        auto right = S.substr(i + 1).find_first_of(C) == string::npos ? 
                     INT_MAX : S.substr(i + 1).find_first_of(C) + 1;
        result.push_back(min(left, right));
      }
    }

    return result;
  }
};