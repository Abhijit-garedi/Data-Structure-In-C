// C program that implements an adjacenty matrix for given graph:

   #include <stdio.h>

     #define MAX 100

void displayMatrix(int adjMatrix[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[MAX][MAX];
    int vertices, edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    printf("Adjacency Matrix:\n");
    displayMatrix(adjMatrix, vertices);

    return 0;
}
