#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Maximum number of vertices

// Queue implementation for BFS
int queue[MAX], front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

// BFS traversal function
void BFS(int adj[MAX][MAX], int visited[MAX], int start, int vertices) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);   // Process current vertex

        // Check all adjacent vertices
        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices, edges;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    int adj[MAX][MAX] = {0};   // Adjacency matrix
    int visited[MAX] = {0};   // Visited array

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // Undirected graph
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal starting from vertex %d:\n", start);
    BFS(adj, visited, start, vertices);

    return 0;
}
