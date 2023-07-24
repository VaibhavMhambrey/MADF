#include <stdio.h>
#include <stdlib.h>
#define sint(x) scanf("%d", &x);

void intmerge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void intmergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        intmergesort(arr, left, mid);
        intmergesort(arr, mid + 1, right);

        intmerge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int intsize;
    printf("Enter size: ");
    sint(intsize);
    int arr[intsize];
    printf("Enter the int array\n");
    for (int i = 0; i < intsize; i++)
        sint(arr[i]);
    intmergesort(arr, 0, intsize - 1);
    printf("Array after merge sort\n");
    printArray(arr, intsize);
    return 0;
}
