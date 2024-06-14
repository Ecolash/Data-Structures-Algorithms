// DOUBLY LINKED LIST
// TRAVERSAL OF A DOUBLY LINKED LIST (from last)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void traversal(struct Node *tail)
{
    while (tail != NULL)
    {
        printf("%d\t", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *tail;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    tail = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->prev = NULL;
    head->next = second;

    second->data = 17;
    second->prev = head;
    second->next = third;

    third->data = 27;
    third->prev = second;
    third->next = tail;

    tail->data = 37;
    tail->prev = third;
    tail->next = NULL;

    traversal(tail);
    return 0;
}
