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
#include <string>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class MagicDictionary {
private:
  vector<string> v;
public:
  /** Initialize your data structure here. */
  MagicDictionary() {
    v = vector<string>();
  }

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    v = vector<string>(dict);
  }

  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word) {
    for (auto s : v) {
      if (check(word, s)) return true;
    }
    return false;
  }

  bool check(string left, string right) {
    int notEqual = 0;
    if (left.size() != right.size()) return false;
    for (auto i = 0; i < left.size() and notEqual < 2; i++) {
      if (left[i] != right[i]) notEqual++;
    }
    return notEqual == 1 ? true : false;
  }
};