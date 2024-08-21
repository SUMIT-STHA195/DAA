#include <stdio.h>
#include <stdlib.h>
#define inf 99999
#define MAX 10
int G[MAX][MAX] = {
    {0, 19, 12},
    {32, 0, 6},
    {45, 11, 0}};
int S[MAX][MAX], n;
int prims()
{
        int C[MAX][MAX];
        int u, v, min_dist, dist[MAX], from[MAX];
        int visited[MAX], ne, i, min_cost, j;

        // create cost[][] matrix,spanning[][]
        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                {
                        if (G[i][j] == 0)
                                C[i][j] = inf;
                        else
                                C[i][j] = G[i][j];
                        S[i][j] = 0;
                }

        // initialise visited[],distance[] and from[]
        dist[0] = 0;
        visited[0] = 1;
        for (i = 1; i < n; i++)
        {
                dist[i] = C[0][i];
                from[i] = 0;
                visited[i] = 0;
        }
        min_cost = 0; // cost of spanning tree
        ne = n - 1;   // no. of edges to be added
        while (ne > 0)
        {

                // find the vertex at minimum distance from the tree
                min_dist = inf;
                for (i = 1; i < n; i++)
                        if (visited[i] == 0 && dist[i] < min_dist)
                        {
                                v = i;
                                min_dist = dist[i];
                        }
                u = from[v];

                // insert the edge in spanning tree
                S[u][v] = dist[v];
                S[v][u] = dist[v];
                ne--;
                visited[v] = 1;

                // updated the distance[] array
                for (i = 1; i < n; i++)
                        if (visited[i] == 0 && C[i][v] < dist[i])
                        {
                                dist[i] = C[i][v];
                                from[i] = v;
                        }
                min_cost = min_cost + C[u][v];
        }
        return (min_cost);
}
int main()
{
        int i, j, cost;
        n = 5;
        cost = prims();
        printf("Spanning tree:");
        for (i = 0; i < n; i++)
        {
                printf("\n");
                for (j = 0; j < n; j++)
                        printf("%d\t", S[i][j]);
        }
        printf("\nMinimum cost = %d", cost);
        return 0;
}
