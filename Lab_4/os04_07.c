#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void* OS04_07_T1(void * args) {
    pid_t pid = getpid();

    for(int i = 1; i <= 75; i++)
    {
        sleep(1);
        printf("OS04_07_T1 PID = %d\n", pid);
    }

}

int main()
{
    pthread_t child;
    int cret;
    pid_t pid = getpid();

    cret = pthread_create(&child, NULL, OS04_07_T1, NULL);

    for(int i = 1; i <= 100; i++)
    {
        sleep(1);
        printf("os04_07 PID = %d\n", pid);
    }

    pthread_join(child, NULL);

    return 0;
}