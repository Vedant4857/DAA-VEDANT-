//
// Created by DELL on 04-09-2025.
//
#include <stdio.h>

#define V 4
#define INF 99999
int min(int a, int b) {
    return (a < b) ? a : b;
}

void printSolution(int dist[V][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydwarshall(int graph[V][V]) {
    int new[V][V];

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            new[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                new[i][j] = min(new[i][j], new[i][k]+new[k][j]);
            }
        }

    }
    printSolution(new);
}
int main() {
    int graph[V][V]= {
        {0,3,INF,7},
        {8,0,2,INF},
        {5,INF,0,1},
        {2,INF,INF,0}
    };
    floydwarshall(graph);
}
