## Sets

**Sets** are abstract data types ([ADT](https://en.wikipedia.org/wiki/Abstract_data_type)) that contain certain-discrete elements, without any particular order. 

In sets **NO duplicates** are allowed.

### Basic operation on sets

**intersection(S, T)**: returns new set with elements found on set **S**, that also belong on set **T**, but no other elements. For instance, the intersection of sets  *S = {2, 3, 4, 5}*  and *T = {1, 3, 6, 7, 8}* is *U = {3}*.

**union(S, T)**: returns new set **U** which contains all elements found both on set **S** and set **T**. As in sets no duplicates are allowed, **U** keeps only the first occurance of each element. For instance, the union of sets *S = {2, 3, 4, 5}* and *T = {1, 3, 6, 7, 8}* is *U = {1, 2, 3, 4, 5, 6, 7, 8}*.

**difference(S, T)**: returns new set which contains elements found on set **S**, but not on set **T**. For instance, the difference of sets *S = {2, 3, 4, 5}* and *T = {1, 3, 6, 7, 8}* denoted as *(S - T)* is *U = {2, 4, 5}*.

**subset(S, T)**: check if all elements in set **S** are also elements of set **T** and returns a truth value (either `true` or `false`). For instance, the set *S = {1, 2}* is subset of *T = {1, 2, 3}*.

**is_element_of(x, S)**: checks whether the value **x** is in the set **S** and returns a truth value (either `true` or `false`).

**is_empty(S)**: checks whether the set **S** contains no elements and returns a truth value (either `true` or `false`).

**equal(S1, S2)**: checks if sets **S1** and **S2** contain all and only the same elements. 

**create(S)**: creates a new, initially empty set structure. 

**build_global(S)**: creates a new set structure that contains all the values of data type. For instance, if we want to create a set **S** that contains all the decimal numbers calling the `create(S)` function, **S** will initialize as empty set. *S = {}}* After calling the `build_global(S)` function, **S** will contain all the numbers from 0 through 9. *S = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}*.

**add(x, S)**: adds the element **x** to **S**, if it is not present already.

**remove(x, S)**: removes the element **x** from **S**, if it is present.