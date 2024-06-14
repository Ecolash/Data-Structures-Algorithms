// ADJACENCY MATRIX OF A DIRECTED GRAPH

#include <stdio.h>
#include <stdlib.h>

#define N 6

struct Edge
{
    int src;
    int dest;
};

void createGraph(struct Edge edges[], int n, int matrix[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        matrix[src][dest] = 1;
    }
}

// Function to print adjacency list representation of a graph
void printGraph(int matrix[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    struct Edge edges[] = {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}};
    int n = sizeof(edges) / sizeof(edges[0]);
    int matrix[N][N];
    createGraph(edges, n, matrix);
    printGraph(matrix);
    return 0;
}
