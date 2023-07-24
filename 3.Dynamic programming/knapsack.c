#include<stdio.h>
#define max 100

void knap(int n, int w[max], int p[max], int knapsack[max][max], int knapwt, int zeroOne[max]){
    int i,j,k;
    for(i=0;i<=n;i++){
        knapsack[i][0]=0;
    }
    for(j=0;j<=knapwt;j++){
        knapsack[0][j]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=knapwt;j++){
            if(w[i]>j){
                knapsack[i][j]=knapsack[i-1][j];
            }
            else{
                if(knapsack[i-1][j]>p[i]+knapsack[i-1][j-w[i]]){
                    knapsack[i][j]=knapsack[i-1][j];
                }else{
                    knapsack[i][j]=p[i]+knapsack[i-1][j-w[i]];
                }
            }
        }
    }
   
    i=n;
    k=knapwt;
    while(i>0 && k>0){
        if(knapsack[i][k]!=knapsack[i-1][k]){
            zeroOne[i]=1;
            k=k-w[i];
        }
        i=i-1;
    }
}
int main(){
    int i,j,n,m,prof,wt;
    int w[max],p[max],knapsack[max][max],zeroOne[max];
    printf("enter no of items\n");
    scanf("%d",&n);
    printf("enter max knapsack weight\n");
    scanf("%d",&m);
    printf("enter weight of items\n\n");
    for(i=1;i<=n;i++){
        printf("enter weight and profit of item %d\n",i);
        scanf("%d",&w[i]);
        scanf("%d",&p[i]);
        printf("\n");
    }
    knap(n,w,p,knapsack,m,zeroOne);
    prof=0;
    wt=0;
    for(i=1;i<=n;i++){
        prof+=zeroOne[i]*p[i];
 wt=0;
    for(i=1;i<=n;i++){
        prof+=zeroOne[i]*p[i];
        wt+=zeroOne[i]*w[i];
    }
    printf("optimal profit:%d\n",prof);
    printf("optimal weight:%d\n",wt);
    return 0;
}
}
