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
    vector<int> partitionLabels(string S) {
      auto result = vector<int> {};
      partitionLabels(S, result);
      return result;
    }

    void partitionLabels(string S, vector<int> & v) {
      if (S.empty()) return;

      auto index = S.find_last_of(S[0]);
      for (int i = 0; i < index; i ++) {
        index = max(S.find_last_of(S[i]), index);
      }

      v.push_back(index + 1);
      partitionLabels(S.substr(index+1), v);
      return;
    }
};

// string x = [](){
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     return "";
// }();
// class Solution {
// public:
//     vector<int> partitionLabels(string S) {
//         vector<int> ans;
//         int i = 0;
//         int s[26] = {0};
//         for(int i = 0; i < S.size(); ++i)
//             s[S[i]-'a'] = i;
//         while(i < S.size()){
//             int j = i, li = s[S[i]-'a'];
//             while(i < li){
//                 i++;
//                 li = max(li, s[S[i]-'a']);
//             }
//             ans.push_back(li - j + 1);
//             i++;
//         }
//         return ans;
//     }
// };