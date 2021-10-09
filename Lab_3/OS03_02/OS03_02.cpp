#include <iostream>
#include <Windows.h>


int main()
{
    DWORD pid = GetCurrentProcessId();
    LPCWSTR childs[2] = 
    {
        L"OS03_02_01.exe",
        L"OS03_02_02.exe"
    };

    STARTUPINFO si1;
    STARTUPINFO si2;
    PROCESS_INFORMATION pi1;
    PROCESS_INFORMATION pi2;

    ZeroMemory(&si1, sizeof(STARTUPINFO));
    si1.cb = sizeof(STARTUPINFO);
    ZeroMemory(&si2, sizeof(STARTUPINFO));
    si2.cb = sizeof(STARTUPINFO);

    if (CreateProcess(childs[0], NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1))
    {
        std::wcout << "Process " << childs[0] << " created" << std::endl;
    }
    else
    {
        std::wcout << "Process " << childs[0] << " not created" << std::endl;
    }
      
    if (CreateProcess(childs[1], NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2))
    {
        std::wcout << "Process " << childs[1] << " created" << std::endl;
    }
    else
    {
        std::wcout << "Process " << childs[1] << " not created" << std::endl;
    }

    

    for (int i = 0; i < 100; i++)
    {
        Sleep(1000);

        std::cout << "PID = " << pid << std::endl;
    }

    HANDLE hProcess[2];
    hProcess[0] = &pi1.hProcess;
    hProcess[1] = &pi2.hProcess;

    WaitForMultipleObjects(2, hProcess, TRUE, INFINITE);

    return 0;
}

