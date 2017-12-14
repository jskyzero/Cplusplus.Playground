/*
Queue (abstract data type)

In computer science, a queue (/ˈkjuː/ kyew) is a particular kind of abstract
data type or collection in which the entities in the collection are kept in
order and the principal (or only) operations on the collection are the addition
of entities to the rear terminal position, known as enqueue, and removal of
entities from the front terminal position, known as dequeue. This makes the
queue a First-In-First-Out (FIFO) data structure. In a FIFO data structure, the
first element added to the queue will be the first one to be removed. This is
equivalent to the requirement that once a new element is added, all elements
that were added before have to be removed before the new element can be removed.
Often a peek or front operation is also entered, returning the value of the
front element without dequeuing it. A queue is an example of a linear data
structure, or more abstractly a sequential collection.

Constructor operations to construct a queue:
i. createQueue( )
// post: creates an empty queue
ii. enqueue(newItem) // [equivalent to add(newItem)]
// post: adds newItem at the end of the queue.
Selector operations to select items of a queue
i. front( )
// post: returns the item at the front of the queue. It does not change the
//queue.
Predicate operations to test Queues
i. isEmpty( )
// post: determines whether a queue is empty
ii. dequeue( )
// post: retrieves and removes the item at the front of the queue.

*/

#include <iostream>
#include <queue>
#include <cassert>

typedef std::queue<int> Queue;

void print_queue(Queue initial_queue) {
  Queue copied_queue = initial_queue;
  while (!copied_queue.empty()) {
    std::cout << copied_queue.front() << "-";
    copied_queue.pop();
  }
  std::cout << "end\n";
}

void practice_queue(void) {
  std::cout << "practice_queue" << std::endl;
  
  // i. createQueue( )
  Queue myqueue;
  // ii. enqueue(newItem)
  myqueue.push(123);
  myqueue.push(456);
  print_queue(myqueue);

  // i. front( )
  assert(myqueue.front() == 123);

  // i. isEmpty( )
  assert(!myqueue.empty());
  // ii. dequeue( )
  myqueue.pop();
  print_queue(myqueue);
}
