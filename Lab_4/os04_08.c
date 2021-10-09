#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void* OS04_08_T1(void * args) {
    pid_t pid = getpid();

    for(int i = 1; i <= 75; i++)
    {
        if(i == 50) {
            printf("-------------- OS04_08_T1 goes to sleep... --------\n");
            sleep(10);
            printf("-------------- OS04_08_T1 wakes up... --------\n");
        }

        sleep(1);
        printf("OS04_07_T1 PID = %d\n", pid);
    }

}

int main()
{
    pthread_t child;
    int cret;
    pid_t pid = getpid();

    cret = pthread_create(&child, NULL, OS04_08_T1, NULL);

    for(int i = 1; i <= 100; i++)
    {
        if(i == 30) {
            printf("-------------- main thread goes to sleep... --------\n");
            sleep(15);
            printf("-------------- main thread wakes up... --------\n");
        }

        sleep(1);
        printf("os04_07 PID = %d\n", pid);
    }

    pthread_join(child, NULL);

    return 0;
}