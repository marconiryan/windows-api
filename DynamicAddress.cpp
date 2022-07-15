uintptr_t getDynamicAddress(HANDLE hProcess, uintptr_t dynamicBaseAddress, std::vector<unsigned int> offsets) {
    uintptr_t dynamicAdress = dynamicBaseAddress;
    for (unsigned int i; i < offsets.size(); i++) {
        ReadProcessMemory(hProcess, (BYTE*)dynamicAdress, &dynamicAdress, sizeof(dynamicAdress), nullptr);
    }
    return dynamicAdress;
}
