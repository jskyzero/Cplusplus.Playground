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
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    return allPathsSourceTarget(graph, 0, graph.size() - 1);
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph, int begin, int end) {
    auto result = vector<vector<int>>();
    if (begin == end) {
      result.push_back(vector<int>{ begin });
      return result;
    } else {
      for (auto p : graph[begin]) {
        for (auto sub_path : allPathsSourceTarget(graph, begin, end)) {
          sub_path.insert(sub_path.begin(), p);
          result.push_back(sub_path);
        }
      }
      return result;
    }
  }
};