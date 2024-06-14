// LINKED LIST
// INSERTION OF ELEMENT IN A LINKED LIST
// Inserting in between (at some index)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *pointer)
{
    while (pointer != NULL)
    {
        printf("%d\t", pointer->data);
        pointer = pointer->next;
    }
    printf("\n");
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); // Creation of a new node
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;    // entering data in new node
    ptr->next = p->next; // linking to next node
    p->next = ptr;       // linking previous node (at index - 1) to created node
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
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    traversal(first);

    printf("\nLinked list after insertion 1\n");
    first = insertAtIndex(first, 10, 2);
    traversal(first);

    printf("\nLinked list after insertion 2\n");
    first = insertAtIndex(first, 20, 4);
    traversal(first);

    printf("\nLinked list after insertion 3\n");
    first = insertAtIndex(first, 14, 1);
    traversal(first);

    return 0;
}
