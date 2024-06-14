// UNDIRECTED GRAPH IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#define N 7

struct Graph
{
    // Adjacency list
    struct Node *head[N];
};

struct Node
{
    int dest;
    struct Node *next;
};

struct Edge
{
    int P1;
    int P2;
};

struct Graph *createGraph(struct Edge edges[], int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    for (int i = 0; i < N; i++)
    {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        int P1 = edges[i].P1;
        int dest = edges[i].P2;
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        new->dest = dest;

        new->next = graph->head[P1];
        graph->head[P1] = new;

        P1 = edges[i].P2;
        dest = edges[i].P1;
        struct Node *new1 = (struct Node *)malloc(sizeof(struct Node));
        new1->dest = dest;

        new1->next = graph->head[P1];
        graph->head[P1] = new1;
    }

    return graph;
}

// Function to print adjacency list representation of a graph
void printGraph(struct Graph *graph)
{
    for (int i = 0; i < N; i++)
    {
        struct Node *ptr = graph->head[i];
        printf("%d ->", i);
        while (ptr != NULL)
        {
            printf(" %d", ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Edge edges[] = {{0, 1}, {1, 5}, {2, 3}, {4, 2}, {6, 3}, {1, 6}};
    int n = sizeof(edges) / sizeof(edges[0]);
    struct Graph *graph = createGraph(edges, n);
    printGraph(graph);
    return 0;
}
