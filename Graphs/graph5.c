// ADJACENCY MATRIX OF A UNDIRECTED GRAPH

#include <stdio.h>
#include <stdlib.h>

#define N 6

struct Graph
{
    int matrix[N][N];
};

struct Edge
{
    int src;
    int dest;
};

struct Graph *createGraph(struct Edge edges[], int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph->matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int x = edges[i].src;
        int y = edges[i].dest;
        graph->matrix[x][y] = 1;
        graph->matrix[y][x] = 1;
    }
    return graph;
}

void printGraph(struct Graph *graph)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    struct Edge edges[] = {{0, 1}, {1, 2}, {2, 0}, {3, 1}, {3, 2}, {4, 5}, {5, 0}};
    int n = sizeof(edges) / sizeof(edges[0]);
    struct Graph *graph = createGraph(edges, n);
    printGraph(graph);
    return 0;
}
