#include <stdio.h>
#define MAX 10
int graph[MAX][MAX], parent[MAX], key[MAX];
int n;
int minKey(int key[], int mstSet[]) {
int min = 999, min_index;
for (int v = 0; v < n; v++) {
if (mstSet[v] == 0 && key[v] < min) {
min = key[v];
min_index = v;
}
}
return min_index;

}

void printMST() {

printf("Edges of Minimum Spanning Tree:\n");
for (int i = 1; i < n; i++) {
printf("Edge: %d - %d, Weight: %d\n", parent[i], i, graph[i][parent[i]]);
}

}

void primMST() {

int mstSet[MAX];

for (int i = 0; i < n; i++) {
key[i] = 999;
mstSet[i] = 0;
}

key[0] = 0;
parent[0] = -1;

for (int count = 0; count < n - 1; count++) {
int u = minKey(key, mstSet);
mstSet[u] = 1;

for (int v = 0; v < n; v++) {
if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
parent[v] = u;
key[v] = graph[u][v];
}
}
}

}

int calculateTotalCost() {
int totalCost = 0;
for (int i = 1; i < n; i++) {
totalCost += graph[i][parent[i]];
}
return totalCost;

}

int main() {

printf("\n\tImplementation of Prim's Algorithm\n");
printf("\nEnter the no. of vertices:");
scanf("%d", &n);
printf("\nEnter the cost adjacency matrix:\n");

for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &graph[i][j]);
}
}

primMST();

printf("\nTotal cost of Minimum Spanning Tree: %d\n", calculateTotalCost());

printMST();

return 0;

}
