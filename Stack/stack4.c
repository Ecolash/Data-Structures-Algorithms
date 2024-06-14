// STACK
// Check if a stack is full

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("Stack is full!");
        return 1;
    }
    else
    {
        printf("Stack is not full!");
        return 0;
    }
};

int main()
{
    struct stack *S; // here stack is a pointer
    S->size = 80;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));
    isFull(S);
    return 0;
}