// GRAPH CONSTRUCTION FROM USER INPUT (ADJACENCY MATRIX VERSION)

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 50

typedef struct
{
    int V;
    int adj[N][N];
} Graph;

Graph *Graph_create(int V)
{
    Graph *g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

void end(Graph *g) { free(g); }

void add_Edge(Graph *g, int v, int w)
{
    g->adj[v][w] = 1;
}

void printGraph(Graph *graph)
{
    int V = graph->V;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Create a graph
    Graph *graph = Graph_create(4);
    add_Edge(graph, 0, 1);
    add_Edge(graph, 0, 2);
    add_Edge(graph, 1, 2);
    add_Edge(graph, 2, 0);
    add_Edge(graph, 2, 3);
    add_Edge(graph, 3, 3);

    printGraph(graph);
    end(graph);
    return 0;
}
