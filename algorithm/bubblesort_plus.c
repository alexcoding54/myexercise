#include <stdio.h>

#define for_each(i, x) \
    for (int i=0; i<x; i++)

void swap(int *m,int *n)
{
    int t = *m;
    *m = *n;
    *n = t;
}

void bubble_sort(int *arr, int n)
{
    int m = 0;

    while (m != n-1) {
        if (arr[m] <= arr[m+1]) {
            m++;
        } else if (arr[m] > arr[m+1]) {
            swap(&arr[m], &arr[m+1]);
            m = 0;
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    
    int arr[n];

    for_each(i, n) {
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);

    for_each(i, n) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}