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

void printLinkedList(Node *head, int cycleStartIndex)
{
    int index = 0;
    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");

        if (index == cycleStartIndex)
        {
            printf(" (cycle starts)");
            break;
        }

        head = head->next;
        index++;
    }
    printf("\n");
}

int main()
{
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

    int cycleIndex = findCycleIndex(head);
    if (cycleIndex != -1)
    {
        printf("The linked list has a cycle starting at index %d.\n", cycleIndex);
        printf("Linked list elements: ");
        printLinkedList(head, cycleIndex);
    }
    else
    {
        printf("The linked list does not have a cycle.\n");
    }

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
