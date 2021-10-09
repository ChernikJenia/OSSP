#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void cycle(int k, char* s, int p)
{
    for(int i = 0;i < k; i++)
    {
        sleep(1);
        printf("%s: PID = %d\n", s, p);
    }
}

int main()
{
    pid_t pid = getpid();
    
    switch(pid = fork())
    {
        case -1: perror("fork error"); exit(-1);
        case 0: cycle(50, "child", pid); exit(0);
        default: cycle(100, "main", pid); wait(NULL);
    }
}