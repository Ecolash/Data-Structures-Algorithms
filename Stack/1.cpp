// STACK
// Push operation

#include <iostream>

struct stack
{
    int size;
    int top;
    int *arr;
};

struct stack *create_stack(int size)
{
    struct stack *S;
    S->size = size;
    S->top = -1;
    S->arr = new int[size];
    return S;
}

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

int main()
{
    struct stack *K = create_stack(5);
    push(K, 1);
    push(K, 2);
    push(K, 3);
    push(K, 4);

    delete (K);
    push(K, 5);
    push(K, 6);
    push(K, 7);
    return 0;
}