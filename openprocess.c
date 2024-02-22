#include <stdio.h>
#include <Windows.h>

int main() {
	HMODULE LoadLib = LoadLibraryA("kernel32.dll");
	DWORD pid = 6628;
	HANDLE hProcess = OpenProcess(0x400 | 0x10, FALSE, pid);

	if (hProcess != FALSE) {
		printf("Open process success %d\n", GetLastError());
		goto conditional_return;
	}
	else {
		printf("Failed to open process %d\n", GetLastError());
		goto conditional_return;
	}
	CloseHandle(hProcess);

conditional_return:
	return hProcess ? 0 : 1;
}