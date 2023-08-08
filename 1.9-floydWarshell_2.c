#include <stdio.h>

#define MAX_V 100
#define INF 999

void printMatrix(int matrix[][MAX_V], int V);

void floydWarshall(int graph[][MAX_V], int V) {
  int matrix[MAX_V][MAX_V], i, j, k;

  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      matrix[i][j] = graph[i][j];

  for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix, V);
}

void printMatrix(int matrix[][MAX_V], int V) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int V, graph[MAX_V][MAX_V];
  printf("Enter the number of vertices: ");
  scanf("%d", &V);
  printf("Enter the graph matrix:\n");
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      scanf("%d", &graph[i][j]);
    }
  }
  floydWarshall(graph, V);
  return 0;
}