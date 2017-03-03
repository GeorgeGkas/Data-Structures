# stack_exalloc

### Do heap operations faster
---

## Why we created stack_exalloc?

Consider the following example: We implement [Stack (ADT)](https://github.com/GeorgeGkas/Data-Structures/tree/master/Stacks) in C with [dynamic arrays](https://github.com/GeorgeGkas/Data-Structures/tree/master/Stacks/usingArrays).

```C
typedef struct {
	int *elems; /* Store our stack elements using dynamic array. */
	int *top; /* The top element of our stack. */
	size_t size; /* The number of elements exist on our stack. */
	long maxCapacity; /* The max capacity of our stack. (-1) If we don't set it. */
} Stack;
```

We don't set a max capacity for our structure, so we are able to insert as many elements as we like (at least as much as there are available memory blocks for use). So `maxCapacity` is `-1`.

We initialize stack with `buildStack()` and call function `pushStack()` every time we want to insert one new element to our array:

```C
int pushStack(Stack *S, int x) {
	// ...
	++(S->size);
	S->elems = realloc(S->elems, sizeof(int) * (S->size));
	S->elems[(S->size)-1] = x;
	S->top = &(S->elems[(S->size)-1]);
	// ...
	return 1;
}
```

**Quiz:** What is wrong with the above function?

**Answer (Spoiler Alert):** We call `realloc()` every time we want to insert a new element. 

And where is the problem with that? Well, for small buffer sizes (eg stack with 100 elements) there is none. But as our structure grows and we end up storing **100.000** or worst **1.000.000** elements, we have to allocate a new buffer, copy the old contents to the new buffer, and then free the old buffer. Most of the times `realloc()` is used to get thing done. For instance, we have to pass a text file which contains numbers for your stack. **O(n^2)** really hurts!

## Meet the magic of exponential allocation.

Instead of allocate a new buffer in each operation, we can allocate a larger one and make a new `realloc()` request only when we need it. The strategy we use is called **exponential growth** and basically we **double** our buffer size each time. 

Then we can come up inserting elements in linear time. When we have to remove elements, we shrink the buffer with the same way (divide the old buffer size by two).

## Library Functions

### stack_ex_insert()

#### Declaration

```C
int stack_ex_insert(Stack *S, int x)
```
#### Parameters

**S**: This is the pointer to Stack data structure memory block previously allocated with malloc, calloc or realloc. If this is NULL, a new block is allocated. This is the data structure we want to add a new element.

**x**: This is the value we want to insert.

#### Return Value

This function returns `0` if the operation succeeded and `COULD_NOT_ALLOCATE` in other case.

### stack_ex_remove()

#### Declaration

```C
int stack_ex_remove(Stack *S)
```
#### Parameters

**S**: This is the pointer to Stack structure memory block previously allocated with malloc, calloc or realloc. This is the Stack we want to remove an element. If this is NULL, we do nothing.

#### Return Value

This function returns `0` if the operation succeeded and `COULD_NOT_ALLOCATE` in other case.
