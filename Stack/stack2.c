// STACK
// Creating A stack (pointer)
// Here the stack is considered a pointer

// This is a dynamic stack

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int main()
{
    struct stack *S; // here stack is a pointer
    S->size = 80;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));
    return 0;
}