// CYCLE DETECTION IN UNDIRECTED GRAPH
// Find if there is a cycle using DFS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

typedef struct
{
    int v;
    struct Node *head[N];
} Graph;

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

void end(Graph *g) { free(g); }

Graph *createGraph(struct Edge edges[], int n, int v)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->v = v;

    for (int i = 0; i < v; i++)
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

void printGraph(Graph *graph)
{
    int v = graph->v;
    for (int i = 0; i < v; i++)
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

bool DFS(Graph *g, int node, int parent, bool *visited)
{
    visited[node] = true;

    struct Node *ptr = g->head[node];
    while (ptr != NULL)
    {
        int t = ptr->dest;
        if (!visited[t])
        {
            if (DFS(g, t, node, visited))
                return true;
        }

        else if (t != parent)
        {
            return true;
        }

        ptr = ptr->next;
    }
    return false;
}

bool isCyclic(Graph *g)
{
    int x = g->v;
    bool visited[x];
    for (int i = 0; i < x; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < x; i++)
    {
        if (!visited[i])
        {
            if (DFS(g, i, -1, visited))
            {
                printf("YES \n");
                return true;
            }
        }
    }
    printf("NO \n");
    return false;
}

int main()
{
    struct Edge edges[] = {{4, 2}, {2, 1}, {1, 3}, {0, 4}, {0, 5}, {5, 6}};
    int n = sizeof(edges) / sizeof(edges[0]);
    Graph *graph = createGraph(edges, n, 7);

    printf("Cycle Detected: ");
    bool x = isCyclic(graph);

    end(graph);
    return 0;
}