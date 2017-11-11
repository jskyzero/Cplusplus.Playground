/*
 * leetcode solution
 * 
 * jskyzero 
 * 
 * */

// universal header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <ciso646>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif


class Solution {
public:
    bool judgeCircle(string m) {
        // also you can travel it and spend time o(n) 
        return (
          count(m.begin(), m.end(), 'U') == count(m.begin(), m.end(), 'D')
        ) and (
          count(m.begin(), m.end(), 'L') == count(m.begin(), m.end(), 'R')
        );
    }
};
