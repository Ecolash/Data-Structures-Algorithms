// Returning index where cycle starts in linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

int findCycleIndex(Node *head)
{
    if (head == NULL || head->next == NULL)
        return -1;

    Node *slow = head;
    Node *fast = head;
    int hasCycle = 0;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            hasCycle = 1;
            break;
        }
    }

    if (!hasCycle)
        return -1;

    // Move one pointer back to head and then move both pointers one step at a time until they meet
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // At this point, both pointers are at the start of the cycle
    int cycleIndex = 0;
    while (head != slow)
    {
        head = head->next;
        slow = slow->next;
        cycleIndex++;
    }

    return cycleIndex;
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

    int cycleIndex = findCycleIndex(head);
    if (cycleIndex != -1)
    {
        printf("The linked list has a cycle starting at index %d.\n", cycleIndex);
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
