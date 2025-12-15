#include "SoftwareDefinitions.h"
#include "SoftwareRealisation.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
	srand(static_cast<unsigned int>(time(nullptr)));

	WNDCLASS SoftwareMainClass = NewWindowClass(THEMEWINDOWCOLOR, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION), L"MainWndClass", SoftwareMainProcedure);
	WNDCLASS SoftwareDiscoveringClass = NewWindowClass(THEMEWINDOWCOLOR, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION), L"DiscoveringWndClass", SoftwareDiscoveringProcedure);

	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	if (!RegisterClassW(&SoftwareDiscoveringClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };

	CreateWindow(L"MainWndClass",L"The Ants Macro", WS_OVERLAPPEDWINDOW | WS_VISIBLE | ES_AUTOVSCROLL | WS_EX_CLIENTEDGE | WS_EX_TOPMOST, 100, 100, 500, 700, NULL, NULL, NULL, NULL);
	while (GetMessageW(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}
	ExitSoftware();

	return 0;
}
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
	WNDCLASS NWC = { 0 };

	NWC.hIcon = Icon;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGColor;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}
LRESULT CALLBACK SoftwareDiscoveringProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		}
		break;
	case WM_CREATE:
		DiscoveringWndWidgets(hWnd);
		break;
	case WM_DESTROY:
		ExitDiscoveringSoftware();
		break;

	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
}
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case OnButtonStartClick:
			isActive = !isActive;
			if (isActive) {
				readTime = CreateThread(NULL, 0, ThreadTimeProgres, NULL, 0, NULL);
				SetWindowTextA(ActiveControlTextStatus, "Active");
				SetActiveTextColor(RGB(0, 255, 0), ActiveControlTextStatus);
				SetActiveTextColor(RGB(0, 255, 0), StatusTextStart);

			}
			else {
				if (readTime) {
					isActive = false;
					CloseHandle(readTime);
					readTime = NULL;
				}
				SetWindowTextA(ActiveControlTextStatus, "inActive");
				SetActiveTextColor(RGB(255, 0, 0), ActiveControlTextStatus);
				SetActiveTextColor(RGB(255, 0, 0), StatusTextStart);
			}
			
			break;
		case OnButtonDiscoverClick:
		{
			isDiscovering = !isDiscovering;
			if(isDiscovering)
				readNewWindow = CreateThread(NULL, 0, ThreadDiscover, NULL, 0, NULL);
			else {
				if (readNewWindow) {
					isDiscovering = false;
					WaitForSingleObject(readNewWindow, INFINITE);
					CloseHandle(readNewWindow);
					readNewWindow = NULL;
				}
			}
			
		}
		default: break;
		}
		break;
	case WM_DISCOVER_PROGRESS: {
		int percent = (int)wp;
		std::string text = std::to_string(percent) + "%";
		SetWindowTextA(DiscoverStatusText, text.c_str());
		SetActiveTextColor(RGB(0, 0, 0), DiscoverStatusText);
		break;
	}
	case WM_TIME_PROGRESS:
	{
		PostMessageA(g_hMainWnd, WM_COMMAND, OnButtonStartClick, 0);
		break;
	}
	case WM_CTLCOLORSTATIC: {
		HDC hdcStatic = (HDC)wp;
		HWND hStatic = (HWND)lp;

		if (hStatic == ActiveControlTextStatus || hStatic == StatusTextStart) {
			SetTextColor(hdcStatic, ActiveTextColor);
			SetBkMode(hdcStatic, TRANSPARENT);
			return (LRESULT)GetStockObject(DC_BRUSH);
		}
		else if (hStatic == StatusTextTime || hStatic == ActiveControlTextStatusTime) {
			SetTextColor(hdcStatic, RGB(0, 0, 0));
			SetBkMode(hdcStatic, TRANSPARENT);
			return (LRESULT)GetStockObject(DC_BRUSH);
		}
		else if (hStatic == DiscoverStatusText) {
			SetTextColor(hdcStatic, RGB(0, 0, 0));
			SetBkMode(hdcStatic, TRANSPARENT);
			return (LRESULT)GetStockObject(DC_BRUSH);
		}
		break;
	}
	case WM_CREATE:
		g_hMainWnd = hWnd;
		readKey = CreateThread(NULL, 0, ReadKeysInput, NULL, 0, NULL);
		MainWndAddMenus(hWnd);
		MainWndWidgets(hWnd);
		break;
	case WM_DESTROY:
		ExitSoftware();
		break;

	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
}
