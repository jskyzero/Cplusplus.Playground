#include <iostream>
#include <cstring>

typedef int data_type;

class HashTable{
 private:
  int mod_num;
  data_type *data; 
 public:
  HashTable(int num) {
    mod_num = num;
    data = new data_type[num];
    memset(data, -1, sizeof(data_type) * num);
  }
  void insert(int num) {
    int index = num % mod_num;
    if (data[index] == -1) {
      data[index] = num;
    } else {
      for (index = index + 1 == mod_num ? 0: index + 1;
          index != num % mod_num;
          index = index + 1 == mod_num ? 0: index + 1) {
            if (data[index] == -1) {
              data[index] = num;
              break;
            }
          }
    }
  }
  void print() {
    for (int i= 0; i < mod_num; i++) {
      std::cout << i << '#';
      if (data[i] == -1) {
        std::cout << "NULL";
      } else {
        std::cout << data[i];
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  int key_num, mod_num, temp_num;
  std::cin >> key_num >> mod_num;
  HashTable myhash(mod_num);
  for (int i = 0; i < key_num; i++) {
    std::cin >> temp_num;
    myhash.insert(temp_num);
  }
  myhash.print();
}