// CIRCULAR LINKED LIST
// DELETION OF ELEMENT IN A CIRCULAR LINKED LIST
// Deleting element at index

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *p = head;
    while (p->next != head)
    {
        printf("Element: %d \n", p->data);
        p = p->next;
    }
    printf("Element: %d \n", p->data);
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

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
    first->next = second;

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = first;

    printf("Circular Linked list before deletion\n");
    traversal(first);

    first = deleteAtIndex(first, 2);
    first = deleteAtIndex(first, 1);

    printf("\nCircular Linked list after deletion\n");
    traversal(first);
    return 0;
}