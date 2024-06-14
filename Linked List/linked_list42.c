// Calculating length of cycle in linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

int getLength(Node *node)
{
    Node *slow = node;
    Node *fast = node;
    int Length = 0;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Cycle detected, calculate cycle length
            do
            {
                slow = slow->next;
                Length++;
            } while (slow != fast);

            return Length;
        }
    }

    return 0; // No cycle
}

int main()
{
    // Creating a linked list with a cycle
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1;

    Node *current = head;

    // Creating a linked list with 10 nodes
    for (int i = 2; i <= 10; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = i;
        current->next = newNode;
        current = newNode;
    }

    // Creating the cycle
    current->next = head->next->next->next; // Creating a cycle of length 3

    int Length = getLength(head);

    if (Length > 0)
    {
        printf("The linked list has a cycle of length: %d\n", Length);
    }
    else
    {
        printf("The linked list does not have a cycle.\n");
    }

    // Freeing the allocated memory
    Node *temp;
    current = head;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
