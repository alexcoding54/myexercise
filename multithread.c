#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

// 全局变量
double start_time = 0;
double end_time = 0;

// 线程函数
void* record_time(void* arg) {
    while (1) {
        usleep(100000); // 暂停100毫秒

        // 更新结束时间
        end_time = (double)clock() / CLOCKS_PER_SEC - start_time;
    }
}

void* add_factorial(void* arg)
{
    long long n = 1;
    int m = 0;

    while (1) {
        usleep(100000);
        n = 1;
        m++; 
        for (int i=m; i!=0; i--) {
            n *= i;
        }
        printf("%ld's factorial is %ld\n", m, n);
    }
}

int main() 
{
    pthread_t tid1, tid2;
    char c;

    // 创建记录时间的线程
    pthread_create(&tid1, NULL, record_time, NULL);
    // 创建整数阶乘叠加的线程
    pthread_create(&tid2, NULL, add_factorial, NULL);

    // 获取开始时间
    start_time = (double)clock() / CLOCKS_PER_SEC;

    while (1) {
        c = getchar(); // 获取输入字符

        // 输出时间
        printf("Now runs: %.3lfs\n", end_time);

        if (c == 'S') {
            break;
        }
    }

    return 0;
}