#include "stackUsingArray.h"

int createStack(Stack *S, size_t n) {
    S->elems = malloc(sizeof(int) * n);
    if (S->elems == NULL) {
        return COULD_NOT_ALLOCATE;
    }

    S->top = NULL;
    S->size = 0;
    S->maxCapacity = S->currAllocatedSize = n;
    return OPERATION_SUCCESS;
}

int buildStack(Stack *S, size_t n, ...) {
    S->elems = NULL;
    S->top = NULL;
    S->size = 0;
    S->currAllocatedSize = 0;
    S->maxCapacity = MAX_CAPACITY_NOT_SET;

    va_list stackElems;
    va_start(stackElems, n);

    int elem;
    for (size_t i = 0; i < n; ++i) {
        elem = va_arg(stackElems, int);
        if (stack_ex_insert(S, elem) == COULD_NOT_ALLOCATE) {
            return COULD_NOT_ALLOCATE;
        }
    }

    return OPERATION_SUCCESS;
}

int pushStack(Stack *S, int x) {
    if (S->maxCapacity == MAX_CAPACITY_NOT_SET) {
        if (stack_ex_insert(S, x) == COULD_NOT_ALLOCATE) {
            return COULD_NOT_ALLOCATE;
        }
    } else {
        if (S->size == S->maxCapacity)  {
            return STACK_IS_FULL;
        } 

        stack_ex_insert(S, x);        
    }
    return OPERATION_SUCCESS;
}

int popStack(Stack *S) {
    if (S->size == 0) {
        return 0;
    }

    if (stack_ex_remove(S) == COULD_NOT_ALLOCATE) {
        return COULD_NOT_ALLOCATE;
    }
    
    return *(S->top);
}

int isEmptyStack(Stack *S) {
    return (S->size ? 0 : 1);
}

int peekStack(Stack *S) {
    if (S->size == 0) {
        return 0;
    }

    return *(S->top);
}

size_t sizeOfStack(Stack *S) {
    return S->size;
}