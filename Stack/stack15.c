// STACK
// Display function

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

struct stack *pop(struct stack *top)
{
    struct stack *newnode;
    newnode = top;

    top = newnode->link;
    free(newnode);
    return top;
}

void display(struct stack *top)
{
    struct stack *temp;
    temp = top;

    printf("Stack : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    struct stack *top; // Top is similar to head of linked list
    top = NULL;

    top = push(top, 5);
    top = push(top, 6);
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    display(top);

    top = pop(top);
    top = pop(top);
    top = pop(top);
    display(top);

    return 0;
}