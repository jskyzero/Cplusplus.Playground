#include <iostream> // for std::cin std::cout 
#include <string> // for std::string
#include <map> // for std::map 
#include <algorithm> // for std::find


typedef std::string String;
typedef std::map<String, String> Map;


void majia(int size) {
  String majia, ip;
  Map temp, out;

  for (int i = 0; i < size; i++) {
    std::cin >> majia >> ip;
    if (temp[ip].length()) {
      out[temp[ip]] = majia;
    } else {
      temp[ip] = majia;
    }
  }

  for (auto & each_user : out) {
    std::cout << each_user.second << " is the MaJia of " << each_user.first << std::endl;
  }
}

int main() {
  int size;
  while (std::cin >> size && size) {
    majia(size);
    std::cout << std::endl;
  }
}