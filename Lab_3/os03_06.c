#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid = getpid();
   
    system("./os03_05_1");
    
    for(int i = 0; i < 100; i++)
    {
        sleep(1);
        printf("os03_06: PID = %d\n", pid);
    }

    return 0;
}