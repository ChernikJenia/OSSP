#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid = getpid();
    char* path = "os03_05_1";

    printf("os03_07 starts");

    execl(path, path, NULL);

    for(int i = 0; i < 100; i++)
    {
        sleep(1);
        printf("PID = %d\n", pid);
    }
    
    printf("os03_07 finishes");

    return 0;
}