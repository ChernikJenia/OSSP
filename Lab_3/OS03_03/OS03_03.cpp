#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

int main()
{
	WORD pid = GetCurrentProcessId();
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	PROCESSENTRY32 peProcessEntry;
	peProcessEntry.dwSize = sizeof(PROCESSENTRY32);

	std::wcout << L"Current PID = " << pid << std::endl << "========================================\n";

	try
	{
		if (!Process32First(snap, &peProcessEntry))
			throw L"Process32First";

		do
		{
			std::wcout << L"Name = " << peProcessEntry.szExeFile << std::endl
				<< L"PID = " << peProcessEntry.th32ProcessID
				<< L", Parent PID = " << peProcessEntry.th32ParentProcessID << std::endl;

			if (peProcessEntry.th32ProcessID == pid)
				std::wcout << L"--> current process\n";

			std::wcout << L"========================================\n";
		} while (Process32Next(snap, &peProcessEntry));

		CloseHandle(snap);
	}
	catch (char* msg)
	{
		std::wcout << L"Error: " << msg << std::endl;
	}

	system("pause");
	return 0;
}
