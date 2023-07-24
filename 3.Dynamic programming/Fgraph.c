#include <stdio.h>
#include <limits.h>
#define V 14

int graph[V][V];
int c[V];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
   int graph[V][V]={
   {0,5,2,3,4,0,0,0,0,0,0,0,0,0 },
   {0,0,0,0,0,7,8,13,12,0,0,0,0,0},
   {0,0,0,0,0,12,13,14,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,17,18,0,0,0,0,0},
   {0,0,0,0,0,0,0,13,14,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,9,8,7,0,0},
   {0,0,0,0,0,0,0,0,0,10,11,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,14,15,0,0},
   {0,0,0,0,0,0,0,0,0,12,13,14,15,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,8},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,9},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,10},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,8},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   };

    // Initialize the first node
    c[0] = 0;
	int i,n,j;
    // Compute the optimal solution for each node
    for (i = 1; i < 14; i++) {
        c[i] = INT_MAX; // set initial value to infinity
        for ( j = 0; j < i; j++) {
            if (graph[j][i] != 0) { 
                c[i] = min(c[i], c[j] + graph[j][i]); 
            }
        }
    }

   // Print the optimal solution for each node
    printf("The optimal solution for each node is:\n");
    for (i = 0; i < 14; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    }
    return 0;
}