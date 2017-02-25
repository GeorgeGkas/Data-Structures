## Sets

**Sets** are abstract data types ([ADT](https://en.wikipedia.org/wiki/Abstract_data_type)) that contain certain-discrete elements, without any particular order. 

In sets **NO duplicates** are allowed.

### Basic operation on sets

**buildSet(S, n, x1, x2, x3, ...)**: creates a set structure **S** with **n** elements x1,x2, x3,…. This function should be called on empty set, else there will be undefined behaviors. To use this function on set that already has been initialized with previous `createSetWithCapacity()` or `buildSet()` call, you have first to call `clearSet()`.

**addElementInSet(S, x)**: adds the element **x** to **S**, if it is not present already.

**removeElementFromSet(S, x)**: removes the element **x** from **S**, if it is present.

**capacityOfSet(S)**: returns the maximum number of elements that **S** can hold. If max capacity has not been set (eg you initialized the set using `buildSet()`) then returns `-1`.

**sizeOfSet(S)**: returns the number of elements in **S**.

**intersectionSet(S, T, U)**: returns new set **U** with elements found on set **S**, that also belong on set **T**, but no other elements. For instance, the intersection of sets  *S = { 2, 3, 4, 5 }*  and *T = { 1, 3, 6, 7, 8 }* is *U = { 3 }*.

**unionSet(S, T, U)**: returns new set **U** which contains all elements found both on set **S** and set **T**. As in sets no duplicates are allowed, **U** keeps only the first occurrence of each element. For instance, the union of sets *S = { 2, 3, 4, 5 }* and *T = { 1, 3, 6, 7, 8 }* is *U = { 1, 2, 3, 4, 5, 6, 7, 8 }*.

**differenceSet(S, T, U)**: returns new set **U** which contains elements found on set **S**, but not on set **T**. For instance, the difference of sets *S = { 2, 3, 4, 5 }* and *T = { 1, 3, 6, 7, 8 }* denoted as *(S - T)* is *U = { 2, 4, 5 }*.

**subSet(S, T)**: check if all elements in set **S** are also elements of set **T** and returns a truth value (either `true` or `false`). For instance, the set *S = { 1, 2 }* is subset of *T = { 1, 2, 3 }*.

**isElementOfSet(S, t)**: checks whether the value **x** is in the set **S** and returns a truth value (either `true` or `false`).

**isEmptySet(S)**: checks whether the set **S** contains no elements and returns either 0 (false) or 1 (true);

**equalSets(S, T)**: checks if sets **S** and **T** contain all and only the same elements. 

**createSetWithCapacity(S, n)**: creates a new, initially empty, set structure capable of holding up to **n** elements. This function should be called on empty set, else there will be undefined behaviors. To use this function on set that already has been initialized with previous `createSetWithCapacity()` or `buildSet()` call, you have first to call `clearSet()`.

**clearSet(S)**: delete all elements of **S**. This function should be called on **non empty** set, else there will be undefined behaviors.

**sumOfSet(S)**: returns the sum of all elements of **S**.

**minSet(S)**: returns the minimum element of **S**.

**maxSet(S)**: returns the maximum element of **S**.

**nearestInSet(S, x)**: returns the element of **S** that is closest in value to **x**. 

**reduceSet(S, f, x)** and **f(index, x)**: iterates through every element in set **S** passing each element found in function **f**. In **f** we need two parameters. The first one **index** is the element from the set **S**. **x** is used as return value (for example you do some manipulations and want to return the final value back to caller function). `reduceSet()` should be called only in initialized sets.


### Implementing Set in C

C has not a build in set data structure in it's core library. However, there are a number of ways, some more appropriate than others, to implement sets in C. Bellow, we list some implementation ideas, together with a time complexity table in big-O for each one. We start with the simplest approach, and we'll move to more sophisticated implementations later.

#### Using Arrays

If the maximum number of elements in the set is small enough, we can use a plain old array. This approach suits well on problems that handles sets with **small** amount of elements. Although, the word **small** here is tricky. How **small** you might consider a set depends on the amount of computer resources that are available for usage, so be careful when you are going to use this implementation.

#### Using Bit Fields

A better approach, well better from the space complexity scope, would be using bit-fields. This approach will give us the benefit to store more items in a set, in contrast to the same implementation with ordinary arrays. The amount of space that will be saved depends on many factors and that's because C data types vary by implementation. The truth is that the real number of space will be saved depends on the compiler and/or the system architecture (x64 or x86).

#### Using Linked Lists

#### Using Red-Black trees
