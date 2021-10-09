#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid = getpid();

    for(;;)
    {
        sleep(1);
        printf("os04_06 PID = %d\n", pid);
    }

    return 0;
}