// test.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "test.h"
#include "DataStruc.h"
#include "ComTool.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
DataStruc* datas = new DataStruc();
ComTool* comtool = new ComTool();

// 此代码模块中包含的函数的前向声明: 
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

HINSTANCE hgInst;
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TEST, szWindowClass, MAX_LOADSTRING);
	hgInst =hInstance;
	HWND hdlg = CreateDialogW(hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), GetDesktopWindow(), (DLGPROC)DlgProc);
	if (!hdlg)
	{
		return 0;
	}
	ShowWindow(hdlg, SW_SHOW);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

INT_PTR CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	int x;
	int y;
	switch (msg)
	{
	case WM_INITDIALOG:
		// 设置对话框的图标  
		SendMessage(hDlg, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(hgInst, MAKEINTRESOURCEW(IDI_SMALL)));
		SetWindowTextW(GetDlgItem(hDlg, IDC_BAUD), (LPCWSTR)L"9600");
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);
		datas->draw(hdc);
		EndPaint(hDlg, &ps);
		return 0;
	case WM_COMMAND:
		if (LOWORD(wParam)==ID_OPEN)//打开串口
		{
			comtool->getAllCom(hDlg, IDC_COM);
			return 0;
		}
		if (LOWORD(wParam)==IDC_TRIGER)//点燃
		{
			datas->invalid();
			InvalidateRect(hDlg, NULL, true);
		}
	case WM_LBUTTONUP:
		x = (int)LOWORD(lParam);
		y = (int)HIWORD(lParam);
		if (datas->click(x, y) == 1) {
			InvalidateRect(hDlg, NULL, true);
		}
		return 0;
	case WM_SYSCOMMAND:
		if (wParam == SC_CLOSE)
		{
			PostQuitMessage(0);//退出  
		}
		return 0;
	}
	
	return (INT_PTR)FALSE;
}
