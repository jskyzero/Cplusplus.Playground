#include <memory>      // for shared_ptr
#include <cstddef>

// main huffman encoding class
class Hunffman {
 private:
  typedef unsigned char uchar;
  // Node type
  struct Node {
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    uchar label;
    uint weight;
    // constructor
    Node(){};
    Node(uint const new_weight) : Node() { weight = new_weight; };
    Node(uchar const new_label, uint const new_weight)
        : Node(new_weight) {
      label = new_label;
    };
  };
 public:
  // void huffmanEncoding(vector<unsigned int> newWeightTable) {}
};