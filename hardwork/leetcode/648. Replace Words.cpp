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
#include <cmath>
#include <iostream>
#include <memory>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class Solution {
public:
  string replaceWords(vector<string>& dict, string sentence) {
    

    for (auto key : dict) {
      auto last_pos = 0;
      while (true) {
        auto key_pos = sentence.find(key, last_pos);
        if (key_pos == string::npos) {
          break;
        }
        else if (key_pos == 0 or sentence[key_pos - 1] == ' ') {
          auto space_pos = sentence.find(" ", key_pos);
          if (space_pos == string::npos) {
            sentence.erase(sentence.begin() + key_pos + key.size(), sentence.end());
          }
          else {
            sentence.erase(sentence.begin() + key_pos + key.size(), sentence.begin() + space_pos);
          }
        }
        last_pos = key_pos + key.size();
      }
    }
    return sentence;
  }
};