/*

 * I do suggest you to view my new bubblesort source code 'bubblesore_plus.c'

 * which is also stroaged in algorithm/. It's more effective than this one

 * 建议去看同一个目录下的 'bubblesort_plus.c' 源码，比这个更高效

 */

#include <stdio.h>

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                // 交换相邻元素的位置
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() 
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, n);
    
    printf("排序后的数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
