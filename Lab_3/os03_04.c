#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main() 
{
    pid_t pid = getpid();
    for(int i = 0; i < 1000; i++) 
    {
        printf("%d-%d\n", pid, i);
        sleep(2);
    }
}