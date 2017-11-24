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
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <string>

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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        auto even = ListNode(0);
        auto even_now = &even;
        auto odd_now = head;
        auto now = head;
        auto n = 1;
        while (now != NULL) {
          auto next = now->next;
          cout << now->val << endl;
          if (0 == n % 2) {
            even_now->next = now;
            even_now = even_now->next;
            even_now->next = NULL;
          } else {
            odd_now->next = now;
            odd_now = odd_now->next;
            odd_now->next = NULL;
          }
          now = next;
          n++;
        }
        odd_now->next = even.next;
        return head;
    }
};