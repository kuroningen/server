#pragma once
#include <tchar.h>
#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

int startWin32DummyWindow(HINSTANCE hThisInstance);
