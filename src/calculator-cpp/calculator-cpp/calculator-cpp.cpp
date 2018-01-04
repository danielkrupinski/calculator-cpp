// calculator-cpp.cpp : definiuje punkt wejścia dla aplikacji
//

#include "stdafx.h"
#include "calculator-cpp.h"

#define MAX_LOADSTRING 100

// Zmienne globalne:
double number = 0;
HWND b1, b2, b3, b4, b5, b6, b7, b8, b9, b0;
HWND bAdd, bSubstr, bMultipl, bDiv;
HINSTANCE hInst;                                // bieżące wystąpienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytułu
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna głównego

// Przekaż dalej deklaracje funkcji dołączonych w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: W tym miejscu umieść kod.


    // Zainicjuj ciągi globalne
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CALCULATORCPP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Wykonaj inicjacje aplikacji:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CALCULATORCPP));

    MSG msg;

    // Główna pętla wiadomości:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNKCJA: MyRegisterClass()
//
//  CEL: Rejestruje klasę okna.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CALCULATORCPP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CALCULATORCPP);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNKCJA: InitInstance(HINSTANCE, int)
//
//   CEL: Zapisuje dojście wystąpienia i tworzy okno główne
//
//   KOMENTARZE:
//
//        W tej funkcji dojście wystąpienia jest zapisywane w zmiennej globalnej i
//        jest tworzone i wyświetlane okno główne programu.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Przechowuj dojście wystąpienia w zmiennej globalnej

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 350, 550, nullptr, nullptr, hInstance, nullptr);

   b1 = CreateWindowEx(0, "BUTTON", "1", WS_CHILD | WS_VISIBLE,
	   0, 0, 50, 50, hWnd, NULL, hInstance, NULL);
   b2 = CreateWindowEx(0, "BUTTON", "2", WS_CHILD | WS_VISIBLE,
	   0, 50, 50, 50, hWnd, NULL, hInstance, NULL);
   b3 = CreateWindowEx(0, "BUTTON", "3", WS_CHILD | WS_VISIBLE,
	   0, 100, 50, 50, hWnd, NULL, hInstance, NULL);
   b4 = CreateWindowEx(0, "BUTTON", "4", WS_CHILD | WS_VISIBLE,
	   0, 150, 50, 50, hWnd, NULL, hInstance, NULL);
   b5 = CreateWindowEx(0, "BUTTON", "5", WS_CHILD | WS_VISIBLE,
	   0, 200, 50, 50, hWnd, NULL, hInstance, NULL);
   b6 = CreateWindowEx(0, "BUTTON", "6", WS_CHILD | WS_VISIBLE,
	   0, 250, 50, 50, hWnd, NULL, hInstance, NULL);
   b7 = CreateWindowEx(0, "BUTTON", "7", WS_CHILD | WS_VISIBLE,
	   0, 300, 50, 50, hWnd, NULL, hInstance, NULL);
   b8 = CreateWindowEx(0, "BUTTON", "8", WS_CHILD | WS_VISIBLE,
	   0, 350, 50, 50, hWnd, NULL, hInstance, NULL);
   b9 = CreateWindowEx(0, "BUTTON", "9", WS_CHILD | WS_VISIBLE,
	   0, 400, 50, 50, hWnd, NULL, hInstance, NULL);
   b0 = CreateWindowEx(0, "BUTTON", "0", WS_CHILD | WS_VISIBLE,
	   0, 450, 50, 50, hWnd, NULL, hInstance, NULL);

   bAdd = CreateWindowEx(0, "BUTTON", "+", WS_CHILD | WS_VISIBLE,
	   280, 250, 50, 50, hWnd, NULL, hInstance, NULL);
   bSubstr = CreateWindowEx(0, "BUTTON", "-", WS_CHILD | WS_VISIBLE,
	   280, 200, 50, 50, hWnd, NULL, hInstance, NULL);
   bMultipl = CreateWindowEx(0, "BUTTON", "*", WS_CHILD | WS_VISIBLE,
	   280, 150, 50, 50, hWnd, NULL, hInstance, NULL);
   bDiv = CreateWindowEx(0, "BUTTON", "/", WS_CHILD | WS_VISIBLE,
	   280, 100, 50, 50, hWnd, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNKCJA: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  CEL: Przetwarza wiadomości dla okna głównego.
//
//  WM_COMMAND — przetwarzaj menu aplikacji
//  WM_PAINT — pomaluj okno główne
//  WM_DESTROY — opublikuj komunikat o rezygnacji i wróć
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
			//Test stuff
			if ((HWND)lParam == b1)
			{
				number = 1;
				MessageBox(hWnd, "Pressed button 1", "Info", MB_ICONINFORMATION);
			}
			if ((HWND)lParam == b2)
				MessageBox(hWnd, "Pressed button 2", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == b3)
				MessageBox(hWnd, "Pressed button 3", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == b4)
				MessageBox(hWnd, "Pressed button 4", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == b5)
				MessageBox(hWnd, "Pressed button 5", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == b6)
				MessageBox(hWnd, "Pressed button 6", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == b7)
				MessageBox(hWnd, "Pressed button 7", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == b8)
				MessageBox(hWnd, "Pressed button 8", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == b9)
				MessageBox(hWnd, "Pressed button 9", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == b0)
				MessageBox(hWnd, "Pressed button 0", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == bAdd)
				MessageBox(hWnd, "Pressed button +", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == bSubstr)
				MessageBox(hWnd, "Pressed button -", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == bMultipl)
				MessageBox(hWnd, "Pressed button *", "Info", MB_ICONINFORMATION);
			if ((HWND)lParam == bDiv)
				MessageBox(hWnd, "Pressed button /", "Info", MB_ICONINFORMATION);
            int wmId = LOWORD(wParam);
            // Analizuj zaznaczenia menu:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: tutaj dodaj kod rysowania używający elementu hdc...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//Procedura obsługi wiadomości dla okna informacji o programie.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
