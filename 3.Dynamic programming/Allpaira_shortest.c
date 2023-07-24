#include <stdio.h>
#include <limits.h>

#define MAX_NODES 4

int graph[MAX_NODES][MAX_NODES];
int A[MAX_NODES][MAX_NODES];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n,i,j,k; 

    int  graph[MAX_NODES][MAX_NODES]={
	{0,5,0,1},
	{4,0,8,3},
	{0,7,0,5},
	{2,4,2,0},
	};

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if(i!=j &&graph[i][j]==0)
                graph[i][j]=INT_MAX;
            A[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < MAX_NODES; k++) {
        for (i = 0; i < MAX_NODES; i++) {
            for (j = 0; j < MAX_NODES; j++) {
                if(A[i][k] + A[k][j]>0)
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]); 
                }
            }
        }
    

    // Print the shortest path between all pairs of nodes
    printf("The shortest path between all pairs of nodes is:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (A[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", A[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
