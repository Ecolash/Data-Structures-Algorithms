// STACK
// Pop operation

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

// NOTE : Can't pop when stack is empty (stack underflow)

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        printf("Popped %d out of Stack\n", val);
        ptr->top--;
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

    // Popping elements
    pop(S);
    pop(S);
    pop(S);
    pop(S);
    pop(S);

    return 0;
}
