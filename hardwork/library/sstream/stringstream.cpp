#include <iostream>
#include <string>
#include <sstream>

int main() {
  int num = 0;
  int total = 0;
  std::string line;

  while (std::cin >> line) {
    std::stringstream ss(line);
    ss >> num;
    total += num;
  }
  std:: cout << total << std::endl;
  return 0;
}