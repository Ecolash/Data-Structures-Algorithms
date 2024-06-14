// CIRCULAR LINKED LIST
// INSERTION OF ELEMENT IN A CIRCULAR LINKED LIST
// Inserting at index

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

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = head;
    int i = 0;

    while (i != index - 1)
    {
        q = q->next;
        i++;
    }

    p->data = data;
    p->next = q->next;
    q->next = p;
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

    printf("Circular Linked list before insertion\n");
    traversal(first);

    first = insertAtIndex(first, 54, 2);
    first = insertAtIndex(first, 58, 3);
    first = insertAtIndex(first, 59, 2);

    printf("\nCircular Linked list after insertion\n");
    traversal(first);
    return 0;
}