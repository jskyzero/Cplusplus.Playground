#include <iostream>

 template <typename E>

class LinkedList {
private:
// public:
  // inner class: linked-list node
  class Node {
  public:
    E data;
    Node * next;
  };
  Node * first;
public:
  LinkedList() {
    first = 0;
  }
 
  ~LinkedList() {
    while (first != 0) {
      removeFirst();
    }
  }
 
  E getFirst() {
    return first->data;
  }
 
  bool isEmpty() {
    return first == 0;
  }
 
// 实现下列4个函数:
  LinkedList(const LinkedList & that);
  LinkedList & operator= (const LinkedList & that);
  void removeFirst() ;
  void addFirst(E data);

  void print() {
    for (Node *temp_node_ptr = first; temp_node_ptr != 0; temp_node_ptr = temp_node_ptr->next) {
      std::cout << temp_node_ptr->data << "-";
    }
      std::cout << std::endl;
  }
};

  template <class data_type>
  LinkedList<data_type>::LinkedList(const LinkedList &that) {
    first = 0;
    LinkedList<data_type> temp_list;
    for (Node *temp_node_ptr = that.first; temp_node_ptr != 0; temp_node_ptr = temp_node_ptr->next) {
      temp_list.addFirst(temp_node_ptr->data);
    }
    for (Node *temp_node_ptr = temp_list.first; temp_node_ptr != 0; temp_node_ptr = temp_node_ptr->next) {
      addFirst(temp_node_ptr->data);
    }
  }

  template <class data_type>
  LinkedList<data_type> &LinkedList<data_type>::operator=(const LinkedList &that) {
    while (first != 0) {
      removeFirst();
    }
    LinkedList<data_type> temp_list;
    for (Node *temp_node_ptr = that.first; temp_node_ptr != 0; temp_node_ptr = temp_node_ptr->next) {
      temp_list.addFirst(temp_node_ptr->data);
    }
    for (Node *temp_node_ptr = temp_list.first; temp_node_ptr != 0; temp_node_ptr = temp_node_ptr->next) {
      addFirst(temp_node_ptr->data);
    }
    return *this;
  }

  template <class data_type>
  void LinkedList<data_type>::removeFirst() {
    Node * node = first;
    first = node->next;
    delete node;  
}

  template <class data_type>
  void LinkedList<data_type>::addFirst(data_type data) {
    Node * node = new Node();
    node->data = data;
    node->next = first;
    first = node;
  }

template <class data_type>
void print_list(const LinkedList<data_type> in_list) {
  LinkedList<data_type> temp_list = in_list;
  while(!temp_list.isEmpty()) {
    std::cout << temp_list.getFirst() << "-";
    temp_list.removeFirst();
  }
  std::cout << std::endl;
}


int main() {
  LinkedList<int> mylist;
  mylist.addFirst(1);
  mylist.addFirst(2);
  LinkedList<int> mylist2 = mylist;
  print_list(mylist2);
  mylist.removeFirst();
  mylist.removeFirst();
}