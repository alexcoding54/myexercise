#include <stdio.h>
#include <stdlib.h>

// 定义桶的数量和范围
#define BUCKET_SIZE 10
#define INPUT_SIZE 10

// 定义桶结构体，包含数据和大小
typedef struct {
    int* data;
    int size;
} Bucket;

void bucketSort(int* arr, int n) 
{
    // 创建桶数组
    Bucket buckets[BUCKET_SIZE];
    
    // 初始化每个桶为空
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].data = NULL;
        buckets[i].size = 0;
    }
    
    // 将数据分配到桶中
    for (int i = 0; i < n; i++) {
        int index = arr[i] / BUCKET_SIZE;
        
        // 动态扩展桶的大小
        buckets[index].data = realloc(buckets[index].data, (buckets[index].size + 1) * sizeof(int));
        buckets[index].data[buckets[index].size] = arr[i];
        buckets[index].size++;
    }
    
    // 对每个桶中的数据进行排序（这里使用插入排序）
    for (int i = 0; i < BUCKET_SIZE; i++) {
        int* data = buckets[i].data;
        int size = buckets[i].size;
        
        for (int j = 1; j < size; j++) {
            int key = data[j];
            int k = j - 1;
            
            while (k >= 0 && data[k] > key) {
                data[k + 1] = data[k];
                k--;
            }
            
            data[k + 1] = key;
        }
    }
    
    // 合并所有桶中的数据到结果数组中
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        int* data = buckets[i].data;
        int size = buckets[i].size;
        
        for (int j = 0; j < size; j++) {
            arr[index] = data[j];
            index++;
        }
        
        // 释放桶的内存
        free(data);
    }
}

int main() 
{
    int arr[INPUT_SIZE] = {5, 2, 8, 9, 1, 3, 7, 6, 4, 0};
    
    printf("Before sorting:\n");
    for (int i = 0; i < INPUT_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    bucketSort(arr, INPUT_SIZE);
    
    printf("\nAfter sorting:\n");
    for (int i = 0; i < INPUT_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
