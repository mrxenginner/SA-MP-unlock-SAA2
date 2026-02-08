#include <windows.h>

uintptr_t GetAddress(uintptr_t address) {
	static auto base = reinterpret_cast<uintptr_t>(GetModuleHandleA("samp.dll"));
	return (base + (uintptr_t)address);
}

template<typename V>
void WriteMemory(size_t address, V value) {
	DWORD oldVP;
	size_t len = sizeof(V);

	VirtualProtect((void*)address, len, PAGE_EXECUTE_READWRITE, &oldVP);
	*(V*)address = value;
	VirtualProtect((void*)address, len, oldVP, nullptr);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH: {
			DisableThreadLibraryCalls(hModule);
			WriteMemory(GetAddress(0x6240C), '\xEB'); // R3
			break;
		}
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH: {
			WriteMemory(GetAddress(0x6240C), '\x74' ); // R3
			break;
		}
	}

	return TRUE;
}