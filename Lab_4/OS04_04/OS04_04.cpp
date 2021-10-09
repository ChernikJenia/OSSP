#include <iostream>
#include <Windows.h>

DWORD WINAPI OS04_04_T1() {
    int pid = GetCurrentProcessId();
    int tid = GetCurrentThreadId();

    for (int i = 1; i < 25; i++) {
        if (i == 25) {
            std::cout << "-------- OS04_02_T1 goes to sleep.... ------------\n";
            Sleep(10000);
            std::cout << "-------- OS04_02_T1 wakes up.... ------------\n";
        }

        Sleep(500);

        std::cout << "OS04_04_T1: PID = " << pid << ", TID = " << tid << std::endl;
    }

    return 0;
}

DWORD WINAPI OS04_04_T2() {
    int pid = GetCurrentProcessId();
    int tid = GetCurrentThreadId();

    for (int i = 1; i <= 125; i++) {
        if (i == 80) {
            std::cout << "-------- OS04_02_T2 goes to sleep.... ------------\n";
            Sleep(15000);
            std::cout << "-------- OS04_02_T2 wakes up.... ------------\n";
        }

        Sleep(500);

        std::cout << "OS04_04_T2: PID = " << pid << ", TID = " << tid << std::endl;
    }

    return 0;
}

int main()
{
    int pid = GetCurrentProcessId();

    DWORD childId1 = NULL,
          childId2 = NULL;

    HANDLE child1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_04_T1, NULL, 0, &childId1),
           child2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_04_T2, NULL, 0, &childId2);

    for (int i = 1; i <= 100; i++) {
        if (i == 30) {
            std::cout << "-------- main thread goes to sleep.... ------------\n";
            Sleep(10000);
            std::cout << "-------- main thread wakes up.... ------------\n";
        }

        Sleep(500);

        std::cout << "main: PID = " << pid << std::endl;
    }

    WaitForMultipleObjects(2, new HANDLE[]{ child1, child2 }, true, INFINITE);
    CloseHandle(child1);
    CloseHandle(child2);
}
