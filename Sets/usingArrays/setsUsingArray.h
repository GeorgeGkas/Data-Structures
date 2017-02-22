#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * Creates a set structure S 
 * with n elements x1,x2, x3,….
 */
void buildSet(int **S, int n, ...);

/**
 * Delete all elements of S.
 */
void deleteSet(int **S);

/**
 * Creates a set structure S 
 * capable of holding up to n elements.
 */
void createSet(int **S, int n);