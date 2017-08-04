#include <iostream>

struct Node {
  int data;
  int left, right;
};

void preorder(Node* node, int n ) {  
    if ( n != 0 ) {  
        std::cout << node[ n ].data << " ";  
        preorder(node, node[ n ].left );  
        preorder(node, node[ n ].right );  
    }  
}  
  
void inorder(Node* node, int n ) {  
    if ( n != 0 ) {  
        inorder(node, node[ n ].left );  
        std::cout << node[ n ].data << " ";  
        inorder(node, node[ n ].right );  
    }  
} 
void binary_search_tree(int size) {
  Node tree[3001];

  std::cin >> tree[1].data;
  tree[1].left = 0;
  tree[1].right = 0;

  for (int i = 1 + 1; i < size + 1; i++) {
    std::cin >> tree[i].data;
    tree[i].left = 0;
    tree[i].right = 0;

    int j = 1;
    while (j != 0) {
      if (tree[i].data < tree[j].data) {
        if (tree[j].left == 0) {
          tree[j].left = i;
          j = 0;
        } else {
          j = tree[j].left;
        }
      } else {
        if (tree[j].right == 0) {
          tree[j].right = i;
          j = 0;
        } else {
          j = tree[j].right;
        }
      }
    }
  }
    inorder(tree, 1);
    std::cout << std::endl;
    preorder(tree, 1);
    std::cout << std::endl;
};

int main() {
  int size;
  while (std::cin >> size && size) {
    binary_search_tree(size);
  }
}