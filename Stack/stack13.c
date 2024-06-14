// STACK
// Push operation

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *link;
};

struct stack *push(struct stack *top, int val)
{
    struct stack *newnode;
    newnode = (struct stack *)malloc(sizeof(struct stack));

    newnode->data = val;
    newnode->link = top;
    top = newnode;
    return top;
}

int main()
{
    struct stack *top; // Top is similar to head of linked list
    top = NULL;

    push(top, 5);
    push(top, 6);
    push(top, 1);
    push(top, 2);
    push(top, 3);

    return 0;
}