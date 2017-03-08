## Queues

**Queues** are abstract data types ([ADT](https://en.wikipedia.org/wiki/Abstract_data_type)) in which we can only insert elements (**enqueue**) to one side of the structure and extract (**dequeue**) elements from the other. Thus, queues are also referred as **FIFO** (*First-in-First-Out*) data structure. In FIFO data structures, the first element added will also be the first one to be removed. We use two pointers, **front** (sometimes called **head**) to denote the first element to be removed from the queue and **rear** (some times called **tail**) to denote the last inserted element. Often, a **peek** operation is defined, returning the value of the front element without removing it.

### Basic operation on queues

**createQueue(Q)**: create an empty queue **Q**.

**enQueue(Q, x)**: enqueue element **x** to the rear of **Q**.

**deQueue(Q)**: dequeue the front element of **Q**, returning it.

**peekQueue(Q)**: returns the front element of the queue **Q**.

**isEmptyQueue(Q)**: checks whether the queue **Q** contains no elements and returns either `0` (not empty) or `1` (empty).

### Implementing Queues in C

#### Using Arrays (circular buffer)

We can create queues using dynamic arrays. However, queues have not limits in max capacity of elements they can contain. We have to consider how to fix overflow problems when we reach the end of the array. We have two options:

- If **n** is the size of the array, then computing indices modulo **n** will turn the array into a circle. This allow the front and rear pointers drift around endlessly in that circle.
- Using exponential allocation ([like we did in our stack implementation](https://github.com/GeorgeGkas/Data-Structures/tree/master/Stacks/usingArrays/stack_exalloc)) we can double the size of the array each time an overflow occurs.

#### Using Doubly Linked Lists

Another option is using [doubly linked lists](https://en.wikipedia.org/wiki/Doubly_linked_list) that have **O(1)** insertion and deletion at both ends.