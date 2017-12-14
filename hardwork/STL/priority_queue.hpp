/*
Priority queue

In computer science, a priority queue is an abstract data type which is like a
regular queue or stack data structure, but where additionally each element has a
"priority" associated with it. In a priority queue, an element with high
priority is served before an element with low priority. If two elements have the
same priority, they are served according to their order in the queue.

*/

#include <iostream>
#include <queue>
#include <cassert>

typedef std::priority_queue<int> PriorityQueue;

void print_priority_queue(PriorityQueue initial_priority_queue) {
  PriorityQueue copied_priority_queue = initial_priority_queue;
  while (!copied_priority_queue.empty()) {
    std::cout << copied_priority_queue.top() << "-";
    copied_priority_queue.pop();
  }
  std::cout << "end\n";
}

void practice_priority_queue(void) {
  std::cout << "practice_priority_queue" << std::endl;
  
  // i. createPriorityQueue( )
  PriorityQueue myqueue;
  // ii. enqueue(newItem)
  myqueue.push(123);
  myqueue.push(456);
  print_priority_queue(myqueue);

  // i. top( )
  assert(myqueue.top() == 456);

  // i. isEmpty( )
  assert(!myqueue.empty());
  // ii. dequeue( )
  myqueue.pop();
  print_priority_queue(myqueue);
}
