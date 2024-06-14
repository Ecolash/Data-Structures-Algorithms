// DOUBLY LINKED LIST
// CREATION OF A DOUBLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

int main()
{
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    first->data = 7;
    first->prev = NULL;
    first->next = second;

    second->data = 17;
    second->prev = first;
    second->next = third;

    third->data = 27;
    third->prev = second;
    third->next = fourth;

    fourth->data = 37;
    fourth->prev = third;
    fourth->next = NULL;

    return 0;
}
