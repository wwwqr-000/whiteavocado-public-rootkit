HMODULE DLL = LoadLibraryExW(L"data/whiteavocado64.dll", nullptr, 0);

using TS = bool (__cdecl*)(const char*, int, int, int, int);
using MB = void (__cdecl*)(const char*, const char*, const char*, const char*, std::string&);
using QS = bool (__cdecl*)(std::string, std::string&);
using DT = void (__cdecl*)(const char*, int, int, int, int, int, int, int, int, int, int, int);
using BRC = void (__cdecl*)(const char*, int, bool);
using ERC = void (__cdecl*)(const char*);
using SRC = void (__cdecl*)(const char*, const char*);
using OV = void (__cdecl*)();
using GUN = const char* (__cdecl*)();
using EK = void (__cdecl*)(const char*, int);

TS const takeScreenshot = reinterpret_cast<TS>(GetProcAddress(DLL, "takeScreenshot"));
MB const msgBox = reinterpret_cast<MB>(GetProcAddress(DLL, "msgBox"));
QS const quietShell = reinterpret_cast<QS>(GetProcAddress(DLL, "quietShell"));
DT const drawTxt = reinterpret_cast<DT>(GetProcAddress(DLL, "drawTxt"));
BRC const beginRecording = reinterpret_cast<BRC>(GetProcAddress(DLL, "startRecording"));
ERC const endRecording = reinterpret_cast<ERC>(GetProcAddress(DLL, "stopRecording"));
SRC const saveRecording = reinterpret_cast<SRC>(GetProcAddress(DLL, "saveRecording"));
OV const showInputDevices = reinterpret_cast<OV>(GetProcAddress(DLL, "showInputDevices"));
GUN const getUsername = reinterpret_cast<GUN>(GetProcAddress(DLL, "getUName"));
GUN const getSelfName = reinterpret_cast<GUN>(GetProcAddress(DLL, "getSelfName"));
ERC const beep = reinterpret_cast<ERC>(GetProcAddress(DLL, "beep"));
EK const emulateKey = reinterpret_cast<EK>(GetProcAddress(DLL, "key"));
