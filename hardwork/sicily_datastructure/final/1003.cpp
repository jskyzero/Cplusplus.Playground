#include <iostream>
#include <cstring>
#include <list>

#define DATA_SIZE 11
typedef int data_type;
typedef std::list<data_type> List;

class hash_table {
 private:
  List data[DATA_SIZE];

 public:
  hash_table() {

  }
  void insert(int num) {
    int index  = num % 11;
    data[index].push_back(num);
  }

  int find(int num) {
    int index  = num % 11;
    int ans = 0;
    for(auto it = data[index].rbegin(); it != data[index].rend(); it++, ans++) {
      if(*it == num) return ans;
    }
    return -1;
  }

};

void do_what(hash_table &myhash) {
  char ch;
  int num;
  std::cin >> ch >> num;
  if(ch == 'F') {
    std::cout << myhash.find(num) << std::endl;
  } else {
    myhash.insert(num);
  }
}

int main() {
  hash_table myhash;
  int times;
  std::cin >> times;
  while (times--) {
    do_what(myhash);
  }
}