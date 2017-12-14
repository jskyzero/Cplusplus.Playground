#include <iostream>
#include <cstring>


struct Node{
  char data;
  int left;
  int right;
};

void pre_order(Node * mytree, int index) {
  std::cout << mytree[index].data;
  if (mytree[index].left != 0) pre_order(mytree, mytree[index].left);
  if (mytree[index].right != 0) pre_order(mytree, mytree[index].right);
}

void binary_tree(int size) {
  int index, left, right, is_root[10001], num = 0, id[10001];
  char data;
  Node mytree[10001];
  memset(is_root, 1, sizeof(is_root)); 

  for (int i = 0; i < size; i++) {
    std::cin >> index;
    std::cin >> mytree[index].data >> mytree[index].left >> mytree[index].right;
    is_root[mytree[index].left] = is_root[mytree[index].right] = 0;
    id[num] = index; num++;
  }
  for (int i = 0; i < num; i++) {
    if (is_root[id[i]]) {
     pre_order(mytree, id[i]);
    }
  }
  
}

int main() {
  int size;
  while (std::cin >> size && size) {
    binary_tree(size);
    std::cout << std::endl;
  }
}