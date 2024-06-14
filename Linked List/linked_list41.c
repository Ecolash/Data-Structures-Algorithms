// Detecting cycle in linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

int hasCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return 0;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }

    return 0;
}

int main()
{
    // Creating a linked list with a cycle
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1;

    Node *second = (Node *)malloc(sizeof(Node));
    second->data = 2;
    head->next = second;

    Node *third = (Node *)malloc(sizeof(Node));
    third->data = 3;
    second->next = third;

    Node *fourth = (Node *)malloc(sizeof(Node));
    fourth->data = 4;
    third->next = fourth;

    // Creating the cycle
    fourth->next = second;

    if (hasCycle(head))
    {
        printf("The linked list has a cycle.\n");
    }
    else
    {
        printf("The linked list does not have a cycle.\n");
    }

    // Remember to free the allocated memory
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
