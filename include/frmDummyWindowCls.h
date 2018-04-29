#pragma once
#include <tchar.h>
#include <windows.h>

class frmDummyWindowCls
{
    public:
        frmDummyWindowCls();
        ~frmDummyWindowCls();
        int start(HINSTANCE hThisInstance);
        /*  This function is called by the Windows function DispatchMessage()  */
        LRESULT CALLBACK windowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    protected:

    private:
};
