// a simple program that implements the adjacency matrix 


   #include <stdio.h>
   #include <stdlib.h>

    #define MAX_VERTICES 10

      void initializeMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
        for (int i = 0; i < vertices; i++) {
          for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
           }
       }
   }
      void addEdge(int matrix[MAX_VERTICES][MAX_VERTICES], int u, int v) {
        matrix[u][v] = 1;
         matrix[v][u] = 1; 
       }


     void displayMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
        for (int i = 0; i < vertices; i++) {
           for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
             }
             printf("\n");
           }
        }

       int main() {
        int vertices = 5;
        int matrix[MAX_VERTICES][MAX_VERTICES];

         initializeMatrix(matrix, vertices);

            addEdge(matrix, 0, 1);
            addEdge(matrix, 0, 4);
            addEdge(matrix, 1, 2);
             addEdge(matrix, 1, 3);
              addEdge(matrix, 1, 4);
               addEdge(matrix, 2, 3);
               addEdge(matrix, 3, 4);

            printf("Adjacency Matrix:\n");
             displayMatrix(matrix, vertices);

               return 0;
        }
