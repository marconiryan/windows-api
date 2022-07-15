uintptr_t getBaseModuleAdress(DWORD processID, const  wchar_t *moduleName) {
    HANDLE hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processID);
    MODULEENTRY32 moduleEntry;
    moduleEntry.dwSize = sizeof(MODULEENTRY32);
    if (hModuleSnap != INVALID_HANDLE_VALUE) {
        if (Module32First(hModuleSnap, &moduleEntry)) {
            do {
                if (!_wcsicmp((moduleEntry.szModule), moduleName)) {
                    uintptr_t modBaseAddr = (uintptr_t) moduleEntry.modBaseAddr;
                    CloseHandle(hModuleSnap);
                    return modBaseAddr;
                }
            } while (Module32Next(hModuleSnap, &moduleEntry));

        }
    }
    CloseHandle(hModuleSnap);
    return 0;
}
