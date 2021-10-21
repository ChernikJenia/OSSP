#include <Windows.h>
#include <iostream>
#include <bitset>

void printProcessPrty(HANDLE h)
{
    DWORD prty = GetPriorityClass(h);
    std::cout << " ----- Current PID = " << GetCurrentProcessId() << " \n";
    switch (prty)
    {
        case IDLE_PRIORITY_CLASS: std::cout << " ----+ priority = IDLE_PRIORITY_CLASS \n"; break;
        case BELOW_NORMAL_PRIORITY_CLASS: std::cout << " ----+ priority = BELOW_NORMAL_PRIORITY_CLASS \n"; break;
        case NORMAL_PRIORITY_CLASS: std::cout << " ----+ priority = NORMAL_PRIORITY_CLASS \n"; break;
        case ABOVE_NORMAL_PRIORITY_CLASS: std::cout << " ----+ priority = ABOVE_NORMAL_PRIORITY_CLASS \n"; break;
        case HIGH_PRIORITY_CLASS: std::cout << " ----+ priority = HIGH_PRIORITY_CLASS \n"; break;
        case REALTIME_PRIORITY_CLASS: std::cout << " ----+ priority = REALTIME_PRIORITY_CLASS \n"; break;
        default: std::cout << " ----+ priority = ? \n"; break;
    }
    return;
}

void printThreadPrty(HANDLE h)
{
    DWORD icpu = SetThreadIdealProcessor(h, MAXIMUM_PROCESSORS);
    DWORD prty = GetThreadPriority(h);
    std::cout << " ---- Current Thread ID = " << GetCurrentThreadId() << "\n";
    std::cout << " ----+ Processor = " << icpu << " \n";
    std::cout << " ----+ MAXProcessors = " << MAXIMUM_PROCESSORS << " \n";

    switch (prty)
    {
        case THREAD_PRIORITY_LOWEST: std::cout << " ----+ priority = THREAD_PRIORITY_LOWEST \n"; break;
        case THREAD_PRIORITY_BELOW_NORMAL: std::cout << " ----+ priority = THREAD_PRIORITY_BELOW_NORMAL \n"; break;
        case THREAD_PRIORITY_NORMAL: std::cout << " ----+ priority = THREAD_PRIORITY_NORMAL \n"; break;
        case THREAD_PRIORITY_ABOVE_NORMAL: std::cout << " ----+ priority = THREAD_PRIORITY_ABOVE_NORMAL \n"; break;
        case THREAD_PRIORITY_HIGHEST: std::cout << " ----+ priority = THREAD_PRIORITY_HIGHEST \n"; break;
        case THREAD_PRIORITY_IDLE: std::cout << " ----+ priority = THREAD_PRIORITY_IDLE \n"; break;
        case THREAD_PRIORITY_TIME_CRITICAL: std::cout << " ----+ priority = THREAD_PRIORITY_TIME_CRITICAL \n"; break;
        default: std::cout << " ----+ priority = ? \n"; break;
    }
    return;
}

void printCycle(DWORD pid, DWORD tid, const char name[20])
{
    unsigned long long d = MAXULONGLONG / 100000000000;
    int k = 0;
    for (unsigned long long i = 0; i < MAXULONGLONG; i++)
    {
        if (i % d == 0) std::cout << ++k << "-" << name << ": PID = " << pid << ", TID = " << tid << " : " << i << "\n";
    }
    return;
}

int main()
{
    HANDLE hp = GetCurrentProcess();
    HANDLE ht = GetCurrentThread();

    std::cout << " =====================OS05_01=======================\n";
    try
    {
        {
            DWORD pa = NULL, sa = NULL, icpu = -1;
            if (!GetProcessAffinityMask(hp, &pa, &sa)) throw "GetProcessAffinityMask";
            std::cout << " Process Affinity Mask: " << std::bitset<8>(pa) << "\n";
            std::cout << " System Affinity Mask: "  << std::bitset<8>(sa) << "\n";
            std::cout << " Available processes: " << std::bitset<8>(pa).count() << "\n";
        }
    }
    catch (char* msg) { std::cout << "Error " << msg << "\n"; }
    
    printProcessPrty(hp);
    printThreadPrty(ht);
    std::cout << "\n\n";

    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();
    printCycle(pid, tid, "OS05_01");
    std::cout << " =====================================================\n";
    system("pause");
    return 0;
}
