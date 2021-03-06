## Stacks

**Stacks** are abstract data types ([ADT](https://en.wikipedia.org/wiki/Abstract_data_type)) in which we can apply two basic operations. Insert an element in the top of the stack, also referred as **push**. Remove an element from the top of the stack, also referred as **pop**. **pop** does not take an element argument, because we remove the last inserted element. This principle is called **LIFO** *(Last In First Out)*. We should always check if stack is full, we say that *overflows*, as well as, when we try to remove an element, we say that the stack *underflows*. To determine where is the "top" of the stack, we apply a pointer to last element of the stack. We then increase the pointer by one, to push an element, and decrease it by one to pop it.
 
### Basic operation on stacks

**createStack(S, n)**: create an empty stack **S** with max capacity **n**.

**buildStack(S, n, x1, x2, ...)**: creates a stack **S** with **n** elements x1,x2, x3,…. This function should be called on empty stack, else there will be undefined behaviors.

**pushStack(S, x)**: adds the element **x** to stack **S**.

**popStack(S)**: removes the element **x** from stack **S** and return it.

**isEmptyStack(S)**: checks whether the stack **S** contains no elements and returns either `0` (not empty) or `1` (empty).

**peekStack(S)**: returns the last inserted element to stack **S** without removing it.

**sizeOfStack(S)**: returns the number of elements in stack **S**.

### Implementing Stacks in C

C does not include stack data structure in it's core library. To create one stack we have two options. Using an dynamic array to hold it's elements or implement it using single linked list.

### Using Arrays (limited number of elements)

When we use a stack implementation with arrays, we have a static capacity. This means that we should check for overflow each time we try to add a new element in stack. Function `buildStack()` is not used here.

### Using Single Linked Lists (unlimited number of elements)

When we implement stacks with single linked lists, we do not set a max capacity for our stack. This means that we do not have to check if our stack overflows. Function `createStack()` is not used here.
