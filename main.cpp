#define _CRT_SECURE_NO_WARNINGSMONSTER_MONSTER_IMAGE_SIZE
//#pragma comment(lib, "msimg32.lib")

#include <windows.h>
#include <random>
#include <atlimage.h>

HINSTANCE hinst;
LPCTSTR lpszClass = "windows program";
LPCTSTR lpszWindowName = "windows program";
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM iParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreinstance,
    LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASSEX WndClass;
    hinst = hInstance;

    WndClass.cbSize = sizeof(WndClass);
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    WndClass.lpfnWndProc = (WNDPROC)WndProc;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInstance;
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.lpszMenuName = MAKEINTRESOURCE(NULL);
    WndClass.lpszClassName = lpszClass;
    WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    RegisterClassEx(&WndClass);

    hWnd = CreateWindow(lpszClass, lpszWindowName, WS_OVERLAPPEDWINDOW,
        0, 0, 800, 700, NULL, (HMENU)NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    while (GetMessage(&Message, 0, 0, 0)) {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HBITMAP hBitmap;
    HDC hDC;
    HDC memdc;

    static RECT winsize;

    switch (iMessage) {
    case WM_CREATE:
        GetClientRect(hWnd, &winsize);
        break;
    case WM_PAINT:
        hDC = BeginPaint(hWnd, &ps);
        hBitmap = CreateCompatibleBitmap(hDC, winsize.right, winsize.bottom);
        memdc = CreateCompatibleDC(hDC);
        SelectObject(memdc, hBitmap);
        BitBlt(hDC, 0, 0, winsize.right, winsize.bottom, memdc, 0, 0, SRCCOPY); //--- 메모리 DC의 그림을 화면 DC에 복사하기
        DeleteObject(hBitmap);
        DeleteDC(memdc);
        EndPaint(hWnd, &ps);
        break;
    case WM_TIMER:
        switch (wParam) {
        }
        break;
    case WM_CHAR:
        switch (wParam) {
        }
        break;
    case WM_KEYDOWN:
        switch (wParam) {
        }
        InvalidateRect(hWnd, NULL, FALSE);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}