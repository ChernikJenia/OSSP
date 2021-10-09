#include <iostream>
#include <Windows.h>

int main()
{
    DWORD pid = GetCurrentProcessId();

    for (;;) 
    {   
        Sleep(1000);
        std::cout << "PID = " << pid << std::endl;
    }
}

