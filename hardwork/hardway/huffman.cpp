#include <ciso646>        // and not or
#include <cstdio>         // for printf
#include <iostream>       // cout
#include <vector>         // vector
#include <queue>          // priority_queue
#include <functional>     // function
#include <string>         // string
#include <memory>         // shared_ptr
#include <iomanip>        // setw
#include <bitset>         // bitset

using namespace std;

struct Node {
  shared_ptr<Node> left;
  shared_ptr<Node> right;
  unsigned char label;
  unsigned int weight;
};

void show_huffman_encoding(shared_ptr<Node> p, unsigned int code, string s) {
  if (not p->left and not p->right) {
    cout << "'" << (char) p->label << "'" 
         << setw(10) << code << "|" 
         << setw(20) << s 
         << endl;
  } else {
    show_huffman_encoding(p->left, (code << 1) + 0, s + "0");
    show_huffman_encoding(p->right, (code << 1) + 1, s + "1");
  }
}

void huffman_encoding(string str) {

  // initial global tables
  auto weight_table = vector<unsigned int>(256, 0);
  // you can also use this type
  // function<bool(shared_ptr<Node>, shared_ptr<Node>)> p (node_comp);
  auto node_comp = [](shared_ptr<Node> left, shared_ptr<Node> right) -> bool {
    return left->weight > right->weight;
  };
  auto min_heap = priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, decltype(node_comp)>(node_comp);

  // set values
  for (auto c : str) {
    weight_table[c]++;
  }

  for (int i = 0; i < weight_table.size(); i++) {
    if (weight_table[i] > 0) {
      auto new_node_ptr = shared_ptr<Node>(new Node());
      new_node_ptr->label = (unsigned char)i;
      new_node_ptr->weight = weight_table[i];
      min_heap.push(new_node_ptr);
    }
  }


  // Main Part
  while (min_heap.size() != 1) {
    auto left = min_heap.top();
    min_heap.pop();

    auto right = min_heap.top();
    min_heap.pop();

    auto new_node_ptr = shared_ptr<Node>(new Node());
    new_node_ptr->left = left;
    new_node_ptr->right = right;
    new_node_ptr->label = (unsigned char)0;
    new_node_ptr->weight = left->weight + right->weight;
    min_heap.push(new_node_ptr);
  }

  show_huffman_encoding(min_heap.top(), 0, "");
}

int main() {
  string str = "this is an example of a huffman tree";
  // no need to print help message
  // cout << "Huffman Encoding" << endl
  //      << "Enter String" << endl;
  cin >> str;
  huffman_encoding(str);

  return 0;
}