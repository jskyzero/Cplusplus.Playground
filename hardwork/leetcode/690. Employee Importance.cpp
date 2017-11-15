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

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class Employee {
 public:
  // It's the unique ID of each node.
  // unique id of this employee
  int id;
  // the importance value of this employee
  int importance;
  // the id of direct subordinates
  vector<int> subordinates;
};

class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    auto e = find_if(employees.begin(), employees.end(),
                     [id](Employee* e) { return e->id == id; });
    int ans = (*e)->importance;
    for (auto id : (*e)->subordinates) {
      ans += getImportance(employees, id);
    }
    return ans;
  }
};