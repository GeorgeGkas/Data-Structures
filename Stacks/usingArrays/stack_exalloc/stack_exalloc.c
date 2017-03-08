#include "stack_exalloc.h"

int stack_ex_insert(Stack *S, int x) {
    ++(S->size);

    if (S->elems == NULL) {
        S->elems = malloc(sizeof(int) * S->size);
        S->currAllocatedSize = S->size;
    } else if (S->size > S->currAllocatedSize) {
        S->currAllocatedSize *= 2;
        S->elems = realloc(S->elems, sizeof(int) * S->size);
    }

    if (S->elems == NULL) {
        return COULD_NOT_ALLOCATE;
    }

    S->elems[(S->size) - 1] = x;
    S->top = &(S->elems[(S->size) - 1]);

    return OPERATION_SUCCESS;
}

int stack_ex_remove(Stack *S) {
    --(S->size);

    if (S->size == (S->currAllocatedSize / 2)) {
        S->elems = realloc(S->elems, sizeof(int) * S->size);
        if (S->elems == NULL) {
            return COULD_NOT_ALLOCATE;
        }
        S->currAllocatedSize = S->size;
    }

    S->top = &(S->elems[S->size]);

    return OPERATION_SUCCESS;
}