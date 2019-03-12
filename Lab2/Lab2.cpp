// Lab2.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Lab2.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр

// Отправить объявления функций, включенных в этот модуль кода:
INT_PTR CALLBACK    MainFormDlgProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.
	HMODULE hRiched = LoadLibraryW(L"riched20.dll");

    // Выполнить инициализацию приложения:
	hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

	HWND hWnd = CreateDialogW(hInstance, MAKEINTRESOURCEW(IDD_MAINFORM), nullptr, MainFormDlgProc);

	if (!hWnd)
	{
		return FALSE;
	}

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB2));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
			if (!IsDialogMessageW(hWnd, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
        }
    }

	FreeLibrary(hRiched);
	
    return (int) msg.wParam;
}



// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK MainFormDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            DestroyWindow(hDlg);
            return (INT_PTR)TRUE;
        }
        break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
    return (INT_PTR)FALSE;
}
