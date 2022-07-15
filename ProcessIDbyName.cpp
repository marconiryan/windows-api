DWORD getProcessIDbyName(std::wstring processName) {
    HANDLE hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);
    if (hProcSnap != INVALID_HANDLE_VALUE) {
        if (Process32First(hProcSnap, &processEntry)) {
            do {
                if (!processName.compare(processEntry.szExeFile)) {
                    DWORD hproc =  processEntry.th32ProcessID;
                    CloseHandle(hProcSnap);
                    return hproc;
                }
            } while (Process32Next(hProcSnap,&processEntry));
        }
    }
    CloseHandle(hProcSnap);
    return 0;
}
