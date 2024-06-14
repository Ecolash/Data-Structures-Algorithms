// CYCLE DETECTION IN DIRECTED GRAPH
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

bool DFS(Graph *g, int node, bool *visited, bool *dfs_visited)
{
    visited[node] = true;
    dfs_visited[node] = true;

    struct Node *ptr = g->head[node];
    while (ptr != NULL)
    {
        int t = ptr->dest;
        if (!visited[t])
        {
            if (DFS(g, t, visited, dfs_visited))
                return true;
        }

        else if (dfs_visited[t])
        {
            return true;
        }

        ptr = ptr->next;
    }

    dfs_visited[node] = true;
    return false;
}

bool isCyclic(Graph *g)
{
    int x = g->v;
    bool visited[x];
    bool dfs_visited[x];

    for (int i = 0; i < x; i++)
    {
        visited[i] = false;
        dfs_visited[i] = false;
    }

    for (int i = 0; i < x; i++)
    {
        if (!visited[i])
        {
            if (DFS(g, i, visited, dfs_visited))
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
    struct Edge edges[] = {{1, 2}, {2, 3}, {1, 4}, {3, 1}};
    int n = sizeof(edges) / sizeof(edges[0]);
    Graph *graph = createGraph(edges, n, 7);

    printf("Cycle Detected: ");
    bool x = isCyclic(graph);

    end(graph);
    return 0;
}