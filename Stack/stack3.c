// STACK
// Check if a stack is empty

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is empty!");
        return 1;
    }
    else
    {
        printf("Stack is not empty!");
        return 0;
    }
};

int main()
{
    struct stack *S; // here stack is a pointer
    S->size = 80;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));
    isEmpty(S);
    return 0;
}