#include <iostream>
#include <cstring>

int main() {
  int in, ans[100], length;
  bool flag = true;
  while (std::cin >> in) {
    if (!flag) std::cout << std::endl;
    flag = false;

    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    length = 1;
    
    for (int i = 0; i < in + 1; i++) {
      // std::cout << in << " "<< i << std::endl;
      for (int j = 0; j < length; j++) {
        ans[j] *=2;
      }
      for (int j = 0; j < length; j++) {
        if (ans[j] > 9) {
          ans[j+1] += ans[j] / 10;
          ans[j] %= 10;
        }
      }
      if(ans[length]) length++;
    }
    ans[0] -= 2;
    while(!ans[length]) length--;
    for (int i = length; i>=0; i--) {
      std::cout << ans[i];
    }
    std::cout << std::endl;
  }
}