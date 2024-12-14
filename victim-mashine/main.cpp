#include <iostream>
#include <windows.h>
#include <vector>
#include <thread>

HMODULE DLL = LoadLibraryExW(L"data/whiteavocado64.dll", nullptr, 0);
using TS = bool (__cdecl*)(const char*, int, int, int, int);
using MB = void (__cdecl*)(const char*, const char*, const char*, const char*, std::string&);
using QS = bool (__cdecl*)(std::string, std::string&);
using DT = void (__cdecl*)(const char*, int, int, int, int, int, int, int, int, int, int, int);
TS const takeScreenshot = reinterpret_cast<TS>(GetProcAddress(DLL, "takeScreenshot"));
MB const msgBox = reinterpret_cast<MB>(GetProcAddress(DLL, "msgBox"));
QS const quietShell = reinterpret_cast<QS>(GetProcAddress(DLL, "quietShell"));
DT const drawTxt = reinterpret_cast<DT>(GetProcAddress(DLL, "drawTxt"));

std::vector<std::thread> threads;

void cls() {
    system("cls");
}

void wait() {
    system("set /p end=");
}

void handleTakeScreenshot() {
    std::cout << "Testing 'handleTakeScreenshot'\n";
    if (!takeScreenshot("screenshot.bmp", 0, 0, 300, 300)) {
        std::cout << "\tERROR -> Could not take a screenshot.\n";
        return;
    }
    std::cout << "\tOK -> Took a screenshot.\n\n";
}

void handleQuietShell() {
    std::cout << "Testing 'handleQuietShell'\n";
    std::string res = "";
    if (!quietShell("echo test123", res)) {
        std::cout << "\tERROR -> Could not execute quietShell.\n";
        return;
    }
    std::cout << "\tOK -> Executed quietShell with result:";
    std::cout << "\t" + res + "\n\n";
}

void handleDrawTxt() {
    std::cout << "Testing 'handleDrawTxt'\n";
    drawTxt("Test123", 10, 10, 110, 110, 0, 255, 0, 0, 0, 0, 24);
    std::cout << "\tOK -> drawn text 'Test123'\n";
}

int main() {
    std::string msgBoxRes = "";
    msgBox("whiteavocado-public-rootkit", "You are currently running a educational rootkit created by whiteavocado. For educational use ONLY!", "", "w", msgBoxRes);

    handleTakeScreenshot();
    handleQuietShell();
    handleDrawTxt();
    return 0;
}
