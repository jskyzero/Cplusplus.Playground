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


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    auto ans = vector<ListNode*>(k);

    auto size = 0;
    auto p = root;
    while (p != NULL) {
      p = p->next;
      size++;
    }

    auto each = size / k;
    auto more = size % k;

    for (auto i = 0; i < k; i++) {
      if (root != NULL) {
        ans[i] = new ListNode(root->val);
        auto p = ans[i];
        auto length = each + (i < more ? 1 : 0);
        root = root->next;

        for (auto j = 1; j < length; j++) {
          p->next = new ListNode(root->val);
          root = root->next;
          p = p->next;
        }
      }
      else {
        ans[i] = NULL;
      }
    }

    return ans;
  }
};