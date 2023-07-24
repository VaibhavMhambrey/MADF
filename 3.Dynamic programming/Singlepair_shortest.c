#include<stdio.h>
#include<limits.h>
#define max_nodes 7

int graph[max_nodes][max_nodes];
int d[max_nodes];

int main(){
	
	int i,j,u,v;
	int graph[max_nodes][max_nodes]={
	{0,4,0,5,0,0,0},
	{0,0,0,-6,0,0,0},
	{0,2,0,0,-4,0,-4},
	{0,0,3,0,-1,-3,0},
	{0,0,0,0,0,-2,1},
	{0,0,0,0,0,0,3},
	{0,0,0,0,0,0,0},
	};
	for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            if(i!=j && graph[i][j]==0)
                graph[i][j]=INT_MAX;
        }
    }

    for(i=0;i<7;i++){
        d[i]=graph[0][i];
       printf("%d ",d[i]);
    }
    printf("\n");
    for( i=1;i<6;i++){
        for(u=0;u<7;u++){
            if(u!=v){
                for( j=0;j<7;j++){
                    if(d[u]>d[j]+graph[j][u] && d[j]+graph[j][u]>0)
                        d[u]=d[j]+graph[j][u];
                }
            }
        }
    }
    for(i=0;i<7;i++){
       
        printf("%d ",d[i]);
    }
}
