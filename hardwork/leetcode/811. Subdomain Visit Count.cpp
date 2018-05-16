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
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    auto table = map<string, int>{};

    auto add_to_table = [](map<string, int> & table, string key, int value) {
      table[key] += value;
    };

    for (auto cpdomain : cpdomains) {
      auto space_index = cpdomain.find_first_of(' ');
      auto times = stoi(cpdomain.substr(0, space_index));

      auto domains = cpdomain.substr(space_index + 1);
      add_to_table(table, domains, times);

      auto point_index = domains.find_first_of('.', 0);
      while (point_index != string::npos) {
        add_to_table(table, domains.substr(point_index + 1), times);
        point_index = domains.find_first_of('.', point_index + 1);
      }
    }

    auto result = vector<string> {};
    for (auto pair: table) {
      result.push_back(to_string(pair.second) + " " + pair.first);
    }
    return result;
  }
};