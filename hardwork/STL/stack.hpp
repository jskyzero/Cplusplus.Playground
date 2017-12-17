/*
Stack (abstract data type)

In computer science, a stack is an abstract data type that serves as a
collection of elements, with two principal operations: push, which adds an
element to the collection, and pop, which removes the most recently added
element that was not yet removed. The order in which elements come off a stack
gives rise to its alternative name, LIFO (for last in, first out). Additionally,
a peek operation may give access to the top without modifying the stack.


Constructor operations to construct a stack:
i. createStack( )
// post: creates an empty Stack
ii. push(newItem)
// post: adds newItem at the top of the stack.
Selector operations to select items of a Stack
i. top( )
// post: returns the top item of the stack. It does not change the stack.
Predicate operations to test Stacks
i. isEmpty( )
// post: determines whether a stack is empty
ii. pop( )
// post: changes the stack by removing the top item.

*/

#include <iostream>
#include <stack>
#include <cassert>


typedef std::stack<int> Stack;

void print_stack(Stack initial_stack) { 
  Stack copied_stack = initial_stack;
  while (!copied_stack.empty()) {
    std::cout << copied_stack.top()<< "-";
    copied_stack.pop();
  }
  std::cout << "end\n";
}

void practice_stack(void) {
  std::cout << "practice_stack" << std::endl;

  // i. createStack( )
  Stack mystack;
  // ii. push(newItem)
  mystack.push(123);
  mystack.push(456);
  print_stack(mystack);

  // i. top ( )
  assert(mystack.top() == 456);

  // i. isEmpty( )
  assert(!mystack.empty());
  // ii. pop( )
  mystack.pop();
  print_stack(mystack);
}