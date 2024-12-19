#include <iostream>
#include <windows.h>
#include <vector>
#include <thread>

#include "classes/dll_setup.hpp"
#include "classes/vkToString.hpp"

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

void handleMouseTP() {
    std::cout << "Testing 'handleMouseTP'\n";
    mouseTP(100, 100);
    std::cout << "\tOK -> moved cursor to (100, 100)\n\n";
}

void handleMouseKey() {
    std::cout << "Testing 'handleMouseKey'\n";
    mouseKey("left_down");
    Sleep(20);
    mouseKey("left_up");
    std::cout << "\tOK -> left-clicked.\n\n";
}

void handleMsgBox() {
    std::cout << "Testing 'handleMsgBox'\n";
    std::string res = "";
    msgBox("whiteavocado-public-rootkit", "This is a test window", "yn", "i", res);
    std::cout << "\tOK -> result: " << res << ".\n\n";
}

void handleDrawLine() {
    std::cout << "Testing 'handleDrawLine'\n";
    drawLine(100, 100, 200, 200, 2, 255, 0, 0, false);
    std::cout << "\tOK -> drew line from (100, 100) to (200, 200)\n\n";
}

void handleGetScreenResolution() {
    std::cout << "Testing 'handleGetScreenResolution'\n";
    int x = 0;
    int y = 0;
    getScreenResolution(x, y);
    std::cout << "\tOK -> result: (" << x << " X " << y << ")\n\n";
}

void handleKeyListener() {
    std::cout << "Testing 'handleKeyListener'\n\tPress a key...\n";
    std::string stat;
    int VK = keyListener(stat);
    std::cout << "\tOK -> result VK code: '" << VK << "' Real key: " << vkToString(VK) << "\n\n";
}

void handleButtonListener() {
    std::cout << "Testing 'handleButtonListener'\n\tPress any mousebutton key...\n";
    std::string stat;
    int index = buttonListener(stat);
    std::cout << "\tOK -> result: ";
    std::string res = "none";
    switch (index) {
        case 0:
            res = "left";
            break;
        case 1:
            res = "right";
            break;
        case 2:
            res = "middle";
            break;
    }
    std::cout << res << " mousebutton.\n\n";
}

int main() {
    std::string msgBoxRes = "";
    msgBox("whiteavocado-public-rootkit", "You are currently running a educational rootkit created by whiteavocado. For educational use ONLY!\n\nDo you want to continue?", "yn", "w", msgBoxRes);
    if (msgBoxRes != "yes") {
        return 0;
    }

    handleTakeScreenshot();
    handleQuietShell();
    handleShowInputDevices();
    handleBeginRecording();
    Sleep(1000);
    handleEndRecording();
    handleSaveRecording();
    handleGetUsername();
    handleGetSelfName();
    handleBeep();
    handleEmulateKey();
    handleMouseTP();
    handleMouseKey();
    handleMsgBox();
    handleDrawLine();
    handleGetScreenResolution();
    handleKeyListener();
    handleButtonListener();
    system("set /p end=");
    return 0;
}
