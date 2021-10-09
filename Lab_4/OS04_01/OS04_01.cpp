#include <iostream>
#include <Windows.h>

int main()
{
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (;;) 
    {   
        Sleep(500);
        std::cout << "PID = " << pid << ", TID = " << tid << std::endl;
    }
}

