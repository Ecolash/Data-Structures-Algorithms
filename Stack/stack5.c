// STACK
// Push operation

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
        return 1;
    }
    else
    {
        return 0;
    }
};

// NOTE : Can't push when stack is full (stack overflow)

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int main()
{
    struct stack *S;
    S->size = 5;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));
    push(S, 1);
    push(S, 2);
    push(S, 3);
    push(S, 4);
    push(S, 5);
    push(S, 6);
    push(S, 7);
    return 0;
}