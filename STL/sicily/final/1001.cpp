#include <iostream>

struct ListNode {
  int data;
  ListNode *next;
};
// 链表类接口如下：
class List {
 public:
  List() {
    head = new ListNode;
    head->next = NULL;
  }

  ~List() {
    ListNode *curNode;
    while (head->next) {
      curNode = head->next;
      head->next = curNode->next;
      delete curNode;
    }
    delete head;
  }

  void print(void) {
    ListNode *curNode = head;
    while (curNode->next) {
      std::cout << curNode->next  << " " <<(curNode->next)->data << "-";
      curNode = curNode->next;
    }
    std::cout << std::endl;
  }

  //在链表第pos(pos>0)个结点之前插入新结点，新结点的值为toadd
  //链表实际结点从1开始计数。
  //调用时需保证pos小等于链表实际结点数
  void insert(int toadd, int pos);

  // Data field
  ListNode *head;  // head指向虚拟头结点，head-next指向第一个实际结点
};

// 请实现如下函数：
void List::insert(int toadd, int pos) {
  auto ptr = head;
  for (int i = 0; i < pos - 1; i++) {
    ptr = ptr->next;
  }
  auto new_node = new ListNode;
  new_node->data = toadd;
  new_node->next = ptr->next;
  ptr->next = new_node;
}

int main() {
  List mylist;
  mylist.insert(1, 1);
  mylist.print();
  mylist.insert(0, 2);
  mylist.print();
  mylist.insert(2, 1);
  mylist.print();
  mylist.insert(3, 1);
  mylist.print();
  mylist.insert(-1, 4);
  mylist.print();
}