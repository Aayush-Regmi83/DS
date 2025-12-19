#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Maximum number of vertices

// DFS function
void DFS(int adj[MAX][MAX], int visited[MAX], int start, int vertices) {
    visited[start] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            DFS(adj, visited, i, vertices);
        }
    }
}

int main() {
    int vertices, edges;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    int adj[MAX][MAX] = {0};   // Adjacency matrix
    int visited[MAX] = {0};   // Track visited vertices

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // Undirected graph
    }

    // Start DFS from vertex 0
    DFS(adj, visited, 0, vertices);

    // Check if all vertices are visited
    int connected = 1;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("The graph is connected.\n");
    else
        printf("The graph is NOT connected.\n");

    return 0;
}
