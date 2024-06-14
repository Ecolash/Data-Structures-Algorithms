// LINKED LIST
// INSERTION OF ELEMENT IN A LINKED LIST
// Inserting after a given node

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

struct Node *insertAfterNode(struct Node *head, struct Node *node_name, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = node_name->next;
    node_name->next = ptr;
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

    printf("\nLinked list after insertion\n");
    first = insertAfterNode(first, first, 20);
    traversal(first);

    printf("\nLinked list after insertion\n");
    first = insertAfterNode(first, second, 69);
    traversal(first);

    printf("\nLinked list after insertion\n");
    first = insertAfterNode(first, third, 21);
    traversal(first);

    printf("\nLinked list after insertion\n");
    first = insertAfterNode(first, second, 51);
    traversal(first);

    printf("\nLinked list after insertion\n");
    first = insertAfterNode(first, fourth, 23);
    traversal(first);

    return 0;
}
