#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid = getpid();

    for(int i = 0; i < 50; i++)
    {
        sleep(1);
        printf("os03_05_1 PID = %d\n", pid);
    }

    return 0;
}