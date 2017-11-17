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

class Solution {
public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int lastPoisoingTime = 0;
    int keepTime = 0;
    for (auto time : timeSeries) {
      if (time >= lastPoisoingTime) {
        //lastPoisoingTime = time + duration;
      }
      else {
        keepTime -= (lastPoisoingTime - time);
      }
        keepTime += duration;
        lastPoisoingTime = time + duration;
    }
    return keepTime;
  }
};