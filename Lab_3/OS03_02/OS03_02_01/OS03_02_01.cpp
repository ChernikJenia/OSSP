#include <iostream>
#include <Windows.h>

int main()
{
    DWORD pid = GetCurrentProcessId();

    for (int i = 0; i < 50; i++)
    {
        Sleep(1000);
        std::cout << "PID = " << pid << std::endl;
    }

    return 0;
}

