#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 6
int prim_algo(int t[size][2], int k, int l);
int G[size][size] = {
    {0, 10, 0, 8, 0, 0},
    {10, 0, 5, 0, 11, 0},
    {0, 5, 0, 7, 3, 12},
    {8, 0, 7, 0, 0, 4},
    {0, 11, 3, 0, 0, 0},
    {0, 0, 12, 4, 0, 0}};

void setlimit()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (G[i][j] == 0)
            {

                G[i][j] = INT_MAX;
            }
        }
    }
}

void minedge(int *k, int *l)
{
    setlimit();
    int min = G[0][0];
    int i, j;
    for (i = 0; i <= size / 2; i++)
    {
        for (j = i; j < size; j++)
        {

            if (G[i][j] < min)
            {
                *k = i;
                *l = j;
                min = G[i][j];
            }
        }
    }
}

void printnear(int near[size])
{
    for (int i = 0; i < size; i++)
        printf("%d ", near[i] + 1);
    printf("\n");
}

int prim_algo(int t[size][2], int k, int l)
{
    int near[size];
    int mincost = 0;
    minedge(&k, &l);
    t[0][0] = k;
    t[0][1] = l;
    for (int i = 0; i < size; i++)
    {
        if (G[i][k] < G[i][l])
            near[i] = k;
        else
            near[i] = l;
    }
    near[k] = 0;
    near[l] = 0;
    mincost += G[k][l];
    for (int i = 1; i < size - 1; i++)
    {
        printnear(near);
        int minid = 0;
        int min = INT_MAX;
        for (int j = 0; j < size; j++)
        {
            if (near[j] > -1 && min > G[j][near[j]])
            {
                printf("%d\n", j);
                min = G[j][near[j]];
                t[i][0] = j;
                t[i][1] = near[j];
                minid = j;
            }
        }
        printf("\n%d\n", minid);
        mincost += min;
        printf("Mincost= %d\n", mincost);
        near[minid] = 0;
        for (int i = 0; i < size; i++)
        {
            if (near[i] > -1 && G[i][near[i]] > G[i][minid])
                near[i] = minid;
        }
    }
    printf("Mincost= %d", mincost);
}
int main()
{
    int t[size][2];
    int k, l;
    prim_algo(t, k, l);
}
