// MERGE TWO SORTED LIST

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverse_all(struct Node *lists[], int n)
{
    for (int i = 0; i < n; i++)
        traverse(lists[i]);
}

struct Node *merge(struct Node *list1, struct Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node *list = NULL;
    if (list1->data <= list2->data)
    {
        list = list1;
        list->next = merge(list1->next, list2);
    }

    else
    {
        list = list2;
        list->next = merge(list1, list2->next);
    }

    return list;
}

struct Node *mergesort(struct Node **lists, int l, int r)
{
    if (l == r)
        return lists[r];
    int mid = (l + r) / 2;
    struct Node *left = mergesort(lists, l, mid);
    struct Node *right = mergesort(lists, mid + 1, r);

    return merge(left, right);
}

struct Node *mergeKLists(struct Node **lists, int listsSize)
{

    if (listsSize == 0)
        return NULL;
    return mergesort(lists, 0, listsSize - 1);
}

int main()
{
    struct Node *head = NULL;
    int n, m, data;

    printf("Enter the number of lists: ");
    scanf("%d", &n);

    struct Node *lists[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter count of elements in List %d : ", i + 1);
        scanf("%d", &m);

        struct Node *head = (struct Node *)malloc(sizeof(struct Node));
        struct Node *temp_head = head;

        for (int j = 0; i < m; i++)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            scanf("%d", &data);
            newNode->data = data;
            newNode->next = NULL;
            temp_head->next = newNode;
            temp_head = newNode;
        }
        head = head->next;
        lists[i] = head;
    }

    printf("Linked list (before merge): \n");
    traverse_all(lists, n);

    printf("---------------------------------------------");

    struct Node *merged = mergeKLists(lists, n);
    printf("Linked list (after merge): ");
    traverse(merged);

    return 0;
}


