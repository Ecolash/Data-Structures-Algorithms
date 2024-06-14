// CIRCULAR LINKED LIST
// INSERTION OF ELEMENT IN A CIRCULAR LINKED LIST
// Inserting at the end

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

struct Node *insertAtLast(struct Node *head, int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;

    struct Node *q = head->next;
    while (q->next != head)
    {
        q = q->next;
    }
    // At this point q points to the last node of this circular linked list
    // We want to add p after q and q becomes last node

    q->next = p;
    p->next = head;
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

    first = insertAtLast(first, 54);
    first = insertAtLast(first, 58);
    first = insertAtLast(first, 59);

    printf("\nCircular Linked list after insertion\n");
    traversal(first);
    return 0;
}