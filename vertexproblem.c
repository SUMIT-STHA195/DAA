
#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices
#define E 7 // Number of edges

// Function to print the vertex cover set
void printVertexCover(bool cover[], int n)
{
    printf("Vertex Cover: ");
    for (int i = 0; i < n; i++)
    {
        if (cover[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Greedy function to find an approximate vertex cover
void vertexCover(int graph[V][V])
{
    bool cover[V] = {false}; // Array to store vertex cover

    for (int u = 0; u < V; u++)
    {
        for (int v = u + 1; v < V; v++)
        {
            // If there is an edge between u and v
            if (graph[u][v] == 1)
            {
                // Add both u and v to the cover
                if (!cover[u] && !cover[v])
                {
                    cover[u] = true;
                    cover[v] = true;
                }
            }
        }
    }

    printVertexCover(cover, V);
}

int main()
{
    int graph[V][V] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0}};

    vertexCover(graph);

    return 0;
}