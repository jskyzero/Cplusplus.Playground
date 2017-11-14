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
#include <cstring>
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

class Solution {
 public:
  string longestPalindrome(string s) { return LCSubstr(s); }

  string LCSubstr(string s) {
    int l[s.size()][s.size()], z = 0, index = 0;

    for (size_t i = 0; i < s.size(); i++) {
      for (size_t j = 0; j < s.size(); j++) {
        if (s[i] == s[s.size() - j - 1]) {
          if (i == 0 or j == 0) {
            l[i][j] = 1;
          } else {
            l[i][j] = l[i - 1][j - 1] + 1;
          }
          if (l[i][j] >= z) {
            if (isPalindromic(s, i - l[i][j] + 1, i + 1)) {
              z = l[i][j];
              index = i;
            }
          }
        } else {
          l[i][j] = 0;
        }
      }
    }
    return s.substr(index - z + 1, z);
  }

  bool isPalindromic(string & str, size_t begin, size_t end) {
    bool isSame = true;
    for (size_t i = begin; isSame and i < (end + begin) / 2; i++) {
      isSame = (str[i] == str[end + begin - i - 1]);
    }
    return isSame;
  }
};

// class Solution {
//  public:
//   string longestPalindrome(string s) {
//     return LCSubstr(s, string(s.rbegin(), s.rend()));
//   }

//   string LCSubstr(string s, string t) {
//     int l[s.size()][t.size()], z = 0;
//     string ans = string(s);

//     for (size_t i = 0; i < s.size(); i++) {
//       for (size_t j = 0; j < s.size(); j++) {
//         if (s[i] == t[j]) {
//           if (i == 0 or j == 0) {
//             l[i][j] = 1;
//           } else {
//             l[i][j] = l[i - 1][j - 1] + 1;
//           }

//           if (l[i][j] > z) {
//             z = l[i][j];
//             // cout << s.substr(i - z + 1, z) << isPalindromic(s.substr(i - z
//             + 1, z)) << endl; if (isPalindromic(s.substr(i - z + 1, z))) {
//               ans = s.substr(i - z + 1, z);
//             }
//           } else if (l[i][j] == z) {
//             if (isPalindromic(s.substr(i - z + 1, z))) {
//               ans = s.substr(i - z + 1, z);
//             }
//           }
//         } else {
//           l[i][j] = 0;
//         }
//       }
//     }
//     return ans;
//   }

//   bool isPalindromic(string str) {
//     return string(str.rbegin(), str.rend()) == str;
//   }
// };

// class Solution {
//  public:
//   string longestPalindrome(string s) {
//     if (s.empty()) return "";
//     if (s.size() == 1) return s;
//     int min_start = 0, max_len = 1;
//     for (int i = 0; i < s.size();) {
//       if (s.size() - i <= max_len / 2) break;
//       int j = i, k = i;
//       while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate
//       characters. i = k+1; while (k < s.size()-1 && j > 0 && s[k + 1] == s[j
//       - 1]) { ++k; --j; } // Expand. int new_len = k - j + 1; if (new_len >
//       max_len) { min_start = j; max_len = new_len; }
//     }
//     return s.substr(min_start, max_len);
// }
// };

int main() {
  auto s = Solution();
  cout << s.longestPalindrome("abcdasdfghjkldcba");

  return 0;
}