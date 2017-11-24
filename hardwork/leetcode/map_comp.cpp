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

class MapSum {
private:
  function<bool(string, string)> comp;

public:
  map<string, int, function<bool(string, string)>> m;

  MapSum() {
    comp = [](string left, string right) { return left.compare(right) < 0; };
    m = map<string, int, function<bool(string, string)>>(comp);
  }

  void insert(string key, int val) {
    cout << "Before insert: size is " << m.size() << endl;

    cout << "insert " << key << ": " << val << endl;

    m[key] = val;

    cout << "After insert: size is " << m.size() << endl;

    cout << "With key " << key << " we have " << m[key] << endl;
    
    if (m.find("a") != m.end()) {
      cout << ">>>>>>>>>> key: a, value: " << m["a"] << endl;
    }

    cout << endl;
  }


};

int main() {
  MapSum obj = MapSum();
  obj.insert("a", 97);
  obj.insert("aaa", 98);
  obj.insert("ae", 99);
  cout << "Final size: " << obj.m.size() << endl;
  auto cmp = [](string left, string right) { return left.compare(right) < 0; };
  cout << boolalpha << cmp("aaa", "a") << endl;
  cout << boolalpha << cmp("a", "aaa") << endl;
}
