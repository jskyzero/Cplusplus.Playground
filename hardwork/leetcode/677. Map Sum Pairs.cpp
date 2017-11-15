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

class MapSum {
 private:
  // function<bool(string, string)> comp;
  map<string, int> m;
 public:
  /** Initialize your data structure here. */
  MapSum() {
    // comp = [](string left, string right) {
    //   return left.compare(right);
    // };
    m = map<string, int>();
  }

  void insert(string key, int val) {
    // cout << key << " " << val << endl;
    m[key] = val;
    // cout << m.size() << " " << m[key] << endl;

    // for (auto i : m) {
    //   cout << i.first << " " << i.second << endl;
    // }
    //   cout << endl << endl;
  }

  int sum(string prefix) {
    int ans = 0;
    for (auto i : m) {
      if (i.first.size() >= prefix.size() and 
          i.first.substr(0, prefix.size()) == prefix) {
            ans += i.second;
      }
    }
    return ans;
  }
};
