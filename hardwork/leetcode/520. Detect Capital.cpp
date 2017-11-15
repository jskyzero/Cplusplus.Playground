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
  bool detectCapitalUse(string word) {
    if (word.empty()) return true;

    bool firstIsUppercase;
    bool otherIsLowercase;
    bool allIsUppercase;
    bool allIsLowercase;

    otherIsLowercase = true;
    firstIsUppercase = isupper(word[0]);
    allIsUppercase = firstIsUppercase;
    allIsLowercase = not firstIsUppercase;

    for (auto it = word.begin() + 1; it != word.end(); it++) {
      bool isUpper = isupper(*it);
      allIsUppercase = allIsUppercase and isUpper;
      otherIsLowercase = otherIsLowercase and not isUpper;
      allIsLowercase = allIsLowercase and not isUpper;
    }

    return (firstIsUppercase and otherIsLowercase) or allIsUppercase or allIsLowercase;
  }
};