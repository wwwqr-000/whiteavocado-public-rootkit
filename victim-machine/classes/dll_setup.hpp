#pragma once

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
using MT = void (__cdecl*)(int, int);
using DL = void (__cdecl*)(int, int, int, int, int, int, int, int, bool);
using GSR = void (__cdecl*)(int&, int&);
using KL = int (__cdecl*)(std::string&);

template<typename T>
T initExternalMethod(const std::string& methodName) {
    T res = reinterpret_cast<T>(GetProcAddress(DLL, methodName.c_str()));
    if (!res) { return nullptr; }
    return res;
}

TS const takeScreenshot = initExternalMethod<TS>("takeScreenshot");
MB const msgBox = initExternalMethod<MB>("msgBox");
QS const quietShell = initExternalMethod<QS>("quietShell");
DT const drawTxt = initExternalMethod<DT>("drawTxt");
BRC const beginRecording = initExternalMethod<BRC>("startRecording");
ERC const endRecording = initExternalMethod<ERC>("stopRecording");
SRC const saveRecording = initExternalMethod<SRC>("saveRecording");
OV const showInputDevices = initExternalMethod<OV>("showInputDevices");
GUN const getUsername = initExternalMethod<GUN>("getUName");
GUN const getSelfName = initExternalMethod<GUN>("getSelfName");
ERC const beep = initExternalMethod<ERC>("beep");
EK const emulateKey = initExternalMethod<EK>("key");
MT const mouseTP = initExternalMethod<MT>("mouseTP");
ERC const mouseKey = initExternalMethod<ERC>("mouseKey");
DL const drawLine = initExternalMethod<DL>("drawLine");
GSR const getScreenResolution = initExternalMethod<GSR>("getScreenResolution");
KL const keyListener = initExternalMethod<KL>("keyListener");
KL const buttonListener = initExternalMethod<KL>("buttonListener");
