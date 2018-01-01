#ifndef HUFFMAN
#define HUFFMAN 1

#include <ciso646>  // for and
#include <map>      // for map
#include <memory>   // for shared_ptr
#include <queue>    // for priority_queue
#include <vector>   // for vector
#include <iomanip>        // setw

#include <BitBuffer.hpp>

typedef unsigned char uchar;

// main huffman encoding class
class Hunffman {
 private:
  // Node type
  struct Node {
    uchar label;
    uint weight;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    // constructor
    Node(){};
    Node(uint const new_weight) : Node() { weight = new_weight; };
    Node(uchar const new_label, uint const new_weight) : Node(new_weight) {
      label = new_label;
    };
    // no sub leaf, left and right is empty
    bool isLeaf() const { return not left and not right; }
  };

 public:
  static std::map<uchar, BitBuffer>& huffmanEncoding(
      std::vector<uint> const& weight_table,
      std::map<uchar, BitBuffer>& transform_table) {
    // min_heap comp
    auto node_comp = [](std::shared_ptr<Node> left,
                        std::shared_ptr<Node> right) -> bool {
      return left->weight > right->weight;
    };
    // min_heap
    auto min_heap = std::priority_queue<std::shared_ptr<Node>,
                                        std::vector<std::shared_ptr<Node>>,
                                        decltype(node_comp)>(node_comp);
    // initial add
    for (uint i = 0; i < weight_table.size(); i++) {
      if (weight_table[i] > 0) {
        auto new_node_ptr =
            std::shared_ptr<Node>(new Node((uchar)i, weight_table[i]));
        min_heap.push(new_node_ptr);
      }
    }

#ifdef DEBUG
    auto new_heap = decltype(min_heap)(min_heap);
    while (not new_heap.empty()) {
      std::cout << std::setw(5) << (uint)new_heap.top()->label << " "
                << std::setw(10) << (uint)new_heap.top()->weight << std::endl;
      new_heap.pop();
    }
#endif
    // make huffman tree
    while (min_heap.size() > 1) {
      auto left = min_heap.top();
      min_heap.pop();

      auto right = min_heap.top();
      min_heap.pop();

      auto new_node_ptr = std::shared_ptr<Node>(
          new Node((uchar)0, left->weight + right->weight));
      new_node_ptr->left = left;
      new_node_ptr->right = right;
      min_heap.push(new_node_ptr);
#ifdef DEBUG
      std::cout << "left = " << (uint)left->label << " "
                << "right = " << (uint)right->label << std::endl;
#endif
    }

    make_transform_table(min_heap.top(), BitBuffer(0, 0), transform_table);
    return transform_table;
  }

  static void make_transform_table(std::shared_ptr<Node> p, BitBuffer bits,
                            std::map<uchar, BitBuffer>& table) {
    if (not p->isLeaf()) {
      // must add a copy
      auto new_bits = BitBuffer(bits);
      make_transform_table(p->left, bits.addBit(0), table);
      make_transform_table(p->right, new_bits.addBit(1), table);
    } else {
      table[p->label] = bits;
#ifdef DEBUG
      std::cout << std::setw(5) << (uint)p->label<< " " 
                << std::setw(10) << (uint)p->weight << " " 
                << bits.size() << std::endl;
#endif
    }
  }
};

#endif