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
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class MyCalendarThree {
 private:
  vector<pair<int, int>> v;
  int old_max;

  struct Part {
    int begin;
    int end;
    int num;
    Part(int begin, int end, int num) : begin(begin), end(end), num(num){};
  };

 public:
  MyCalendarThree() {
    v = vector<pair<int, int>>();
    old_max = 0;
  }

  int book(int start, int end) {
    auto borrow = vector<Part>();
    borrow.push_back(Part(start, end - 1, 1));

    for (auto p : v) {
      for (auto & part : borrow) {
        if(part.begin >= p.first and part.end <= p.second) part.num++;
        if(part.begin >= p.first and part.end <= p.second) part.num++;
      }
    }

    for (auto part : borrow) {
      old_max = max(part.num, old_max);
    }

    v.push_back(make_pair(start, end - 1));
    return old_max;
  }
};