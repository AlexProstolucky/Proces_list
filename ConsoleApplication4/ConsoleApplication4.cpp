#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

void ListProcesses() {
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        std::cerr << "Помилка при створенні знімку процесів" << std::endl;
        return;
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hProcessSnap, &pe32)) {
        std::cerr << "Помилка при отриманні інформації про процес" << std::endl;
        CloseHandle(hProcessSnap);
        return;
    }

    do {
        std::cout << "PID: " << pe32.th32ProcessID << " Назва: " << pe32.szExeFile << std::endl;
    } while (Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
}

int main() {
    SetConsoleOutputCP(1251);
    int interval = 5000; /

    while (true) {
        ListProcesses();
        Sleep(interval); 

    return 0;
}
