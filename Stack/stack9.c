// STACK
// Peek operation
// Peeking element at ith position from top

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

void peek(struct stack *stack, int i)
{
    int arrayIndex = stack->top - i + 1;
    if (arrayIndex < 0)
    {
        printf("Not a valid position for the stack\n");
    }
    else
    {
        printf("Element at position %d in the stack is %d\n", i, stack->arr[arrayIndex]);
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

    peek(S, 1);
    peek(S, 2);
    peek(S, 3);
    peek(S, 4);
    peek(S, 5);
    peek(S, 6);
    peek(S, 7);
    return 0;
}