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
#include <string>

using namespace std;

// for debug output
#ifndef LEET_CODE_DEBUG
#define LEET_CODE_DEBUG 1
#endif

class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    if (board[click[0]][click[1]] == 'M') {
      board[click[0]][click[1]] = 'X';
    }

    if (board[click[0]][click[1]] == 'E') {
      auto adjacent = getAllAdjacent(board, click);
      auto mineNumber = 0;
      for (auto each : adjacent) {
        if (board[each[0]][each[1]] == 'M') mineNumber++;
      }

      if (mineNumber > 0) {
        board[click[0]][click[1]] = mineNumber + '0';
      }
      else {
        board[click[0]][click[1]] = 'B';
        for (auto each : adjacent) {
          updateBoard(board, each);
        }
      }
    }
    return board;
  }

  vector<vector<int>> getAllAdjacent(vector<vector<char>>& board, vector<int>& click) {
    auto ans = vector<vector<int>>();
    int move[][2] = { {-1, -1}, { -1, 0 }, { -1, 1 }, 
                      { 1, -1 },{  1, 0 }, {  1, 1 }, 
                      { 0, -1 },{ 0, 1 } };

    for (auto i = 0; i < 8; i++) {
      auto each = vector<int>(click);
      each[0] += move[i][0];
      each[1] += move[i][1];
      if (isValidPosition(board, each)) ans.push_back(each);
    }
    return ans;
  }

  bool isValidPosition(vector<vector<char>>& board, vector<int>& click) {
    return click[0] >= 0 and click[0] < board.size() and click[1] >= 0 and click[1] < board[0].size();
  }
};