// DIRECTED WEIGHTED GRAPH IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#define N 6

struct Graph
{
    // Adjacency list
    struct Node *head[N];
};

struct Node
{
    int dest;
    int weight;
    struct Node *next;
};

struct Edge
{
    int src;
    int dest;
    int weight;
};

struct Graph *createGraph(struct Edge edges[], int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    for (int i = 0; i < N; i++)
    {
        graph->head[i] = NULL;
    }

    // Add edges to the directed graph one by one
    for (int i = 0; i < n; i++)
    {
        // Get the source and destination vertex
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        new->dest = dest;
        new->weight = weight;

        new->next = graph->head[src];
        graph->head[src] = new;
    }
    return graph;
}

void printGraph(struct Graph *graph)
{
    for (int i = 0; i < N; i++)
    {
        struct Node *ptr = graph->head[i];
        printf("%d ->", i);
        while (ptr != NULL)
        {
            printf(" %d (%d)", ptr->dest, ptr->weight);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Edge edges[] = {{0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {4, 5, 1}, {5, 4, 3}};
    int n = sizeof(edges) / sizeof(edges[0]);
    struct Graph *graph = createGraph(edges, n);
    printGraph(graph);
    return 0;
}
