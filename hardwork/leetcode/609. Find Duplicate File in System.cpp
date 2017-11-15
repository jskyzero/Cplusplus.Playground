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
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class Solution {
 public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    auto files = map<string, vector<string>>();
    auto ans = vector<vector<string>>();

    for (auto path : paths) {
      auto space_it = find(path.begin(), path.end(), ' ');
      auto title = string(path.begin(), space_it);
      path = string(space_it + 1, path.end()) + " ";

      while (not path.empty()) {
        space_it = find(path.begin(), path.end(), ' ');
        auto each = string(path.begin(), space_it);
        path = string(space_it + 1, path.end());

        auto name_it = find(each.begin(), each.end(), '(');
        auto name = string(each.begin(), name_it);
        auto content = string(name_it + 1, each.end() - 1);

        // auto isFound = false;
        // for (auto i = 0; i < v.size(); i++) {
        //   if (v[i] == content) {
        //     isFound = true;
        //     ans[i].push_back(title + "/" + name);
        //   }
        // }
        // if (not isFound) {
        //   v.push_back(content);
        //   ans.push_back(vector<string>{title + "/" + name});
        // }

        if (files[content].empty()) {
          files[content].push_back(title + "/" + name);
        } else {
          files[content].push_back(title + "/" + name);
        }
      }
    }

    for (auto file : files) {
      if (file.second.size() >= 2)
        ans.push_back(file.second);
    }
    return ans;
  }
};