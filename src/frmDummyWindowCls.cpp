#include "frmDummyWindowCls.h"
#pragma once

frmDummyWindowCls::frmDummyWindowCls()
{
    //ctor
}

frmDummyWindowCls::~frmDummyWindowCls()
{
    //dtor
}

int frmDummyWindowCls::start(HINSTANCE hThisInstance)
{
    TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;

    /* The Window structure */
    wincl.hInstance     = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc   = this->windowProcedure;      /* This function is called by windows */
    wincl.cbSize        = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon        = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm      = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor      = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                   /* No menu */
    wincl.cbClsExtra   = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra   = 0;                      /* structure or the window instance */

    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl)) {
        return 0;
    }

    /* The class is registered, let's create the program*/
   CreateWindowEx (
       0,                   /* Extended possibilites for variation */
       szClassName,         /* Classname */
       _T("Code::Blocks Template Windows App"),       /* Title Text */
       WS_OVERLAPPEDWINDOW, /* default window */
       CW_USEDEFAULT,       /* Windows decides the position */
       CW_USEDEFAULT,       /* where the window ends up on the screen */
       544,                 /* The programs width */
       375,                 /* and height in pixels */
       HWND_DESKTOP,        /* The window is a child-window to desktop */
       NULL,                /* No menu */
       hThisInstance,       /* Program Instance handler */
       NULL                 /* No Window Creation data */
    );

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }
    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */
LRESULT CALLBACK frmDummyWindowCls::windowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
