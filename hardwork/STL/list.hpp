/*
List (abstract data type)

In computer science, a list or sequence is an abstract data type that represents
a countable number of ordered values, where the same value may occur more than
once. An instance of a list is a computer representation of the mathematical
concept of a finite sequence; the (potentially) infinite analog of a list is a
stream.[1]:§3.5 Lists are a basic example of containers, as they contain other
values. If the same value occurs multiple times, each occurrence is considered a
distinct item.

Constructor operations to construct Lists
i. createList to create an empty List
ii. add operation to add data to a List
Selector operations to select items of a List
i. get to return one item at a particular position.
Predicate operations to test Lists
i. isEmpty to test whether the List is empty
ii. remove operation to delete a data item from a List

*/

#include <iostream>
#include <list>
#include <cassert>

typedef std::list<int> List;

void print_list(List initial_list) {
  List copied_list = initial_list;
  for (auto& num : copied_list) {
    std::cout << num << "-";
  }
  std::cout << "end" << std::endl;
}

void practice_list(void) {
  std::cout << "practice_list" << std::endl;
  // i. createList to create an empty List
  List mylist;
  // ii. add operation to add data to a List
  mylist.push_back(123);
  mylist.push_back(456);
  print_list(mylist);

  // i. get to return one item at a particular position.
  auto mylist_it = mylist.begin();
  assert(*(++mylist_it) == 456);

  // i. isEmpty to test whether the List is empty
  assert(!mylist.empty());
  // ii. remove operation to delete a data item from a List
  mylist.erase(mylist_it);
  print_list(mylist);

  // test insert;
  mylist.insert(mylist.begin(), 1);
  print_list(mylist);

  mylist.insert(mylist.begin(), mylist.begin(), mylist.end());
  print_list(mylist);
  mylist.clear();
}