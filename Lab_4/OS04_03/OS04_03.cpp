#include <iostream>
#include <Windows.h>

DWORD WINAPI OS04_03_T1() {
    int pid = GetCurrentProcessId();
    int tid = GetCurrentThreadId();

    for (int i = 0; i < 50; i++) {
        Sleep(1000);

        std::cout << "PID = " << pid << ", TID = " << tid << std::endl;
    }

    return 0;
}

DWORD WINAPI OS04_03_T2() {
    int pid = GetCurrentProcessId();
    int tid = GetCurrentThreadId();

    for (int i = 0; i < 125; i++) {
        Sleep(500);

        std::cout << "PID = " << pid << ", TID = " << tid << std::endl;
    }

    return 0;
}

int main()
{
    int pid = GetCurrentProcessId();

    DWORD childId1 = NULL,
        childId2 = NULL;

    HANDLE child1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_03_T1, NULL, 0, &childId1),
        child2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_03_T2, NULL, 0, &childId2);

    for (int i = 1; i <= 100; i++) {
        Sleep(500);

        if (i == 20) {
            SuspendThread(child1);
            std::cout << "-------- c1 suspended -------\n";
        }
        else if (i == 40) {
            SuspendThread(child2);
            std::cout << "-------- c2 suspended -------\n";
        }
        else if (i == 60) {
            ResumeThread(child1);
            std::cout << "-------- c1 resumed -------\n";
        }

        std::cout << "i:" << i <<  "---------- PID = " << pid << std::endl;
    }

    ResumeThread(child2);
    std::cout << "-------- c2 resumed -------\n";

    WaitForMultipleObjects(2, new HANDLE[]{ child1, child2 }, true, INFINITE);
    CloseHandle(child1);
    CloseHandle(child2);
}
