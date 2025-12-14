#include "SoftwareDefinitions.h"


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
	srand(static_cast<unsigned int>(time(nullptr)));

	WNDCLASS SoftwareMainClass = NewWindowClass(THEMEWINDOWCOLOR, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION), L"MainWndClass", SoftwareMainProcedure);

	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };

	CreateWindow(L"MainWndClass",L"First c++ window", WS_OVERLAPPEDWINDOW | WS_VISIBLE | ES_AUTOVSCROLL, 100, 100, 500, 700, NULL, NULL, NULL, NULL);
	while (GetMessageW(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}

	if (readThread) {
		isDiscovering = false;
		WaitForSingleObject(readThread, INFINITE);
		CloseHandle(readThread);
		readThread = NULL;
	}

	return 0;
}

DWORD WINAPI ThreadDiscover(LPVOID lpParameter) {
	std::string textOnLabel = "";
	for (int i = 1; i <= 100 && isDiscovering; i++) {
		if (!isDiscovering) break;
		PostMessageA(g_hMainWnd,WM_DISCOVER_PROGRESS,i,0);
		Sleep(100);
	}
	return 0;
}

void ExitSoftware(void) {
	THEMEWINDOWCOLOR->unused;
	if (readThread) {
		isDiscovering = false;
		WaitForSingleObject(readThread, INFINITE);
		CloseHandle(readThread);
		readThread = NULL;
	}

	PostQuitMessage(0);
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
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case OnButtonStartClick:
			if (isActive) {
				SetWindowTextA(ActiveControlTextStatus, "inActive");
				SetActiveTextColor(RGB(255, 0, 0), ActiveControlTextStatus);
				SetActiveTextColor(RGB(255, 0, 0), StatusTextStart);
			}
			else {
				SetWindowTextA(ActiveControlTextStatus, "Active");
				SetActiveTextColor(RGB(0, 255, 0), ActiveControlTextStatus);
				SetActiveTextColor(RGB(0, 255, 0), StatusTextStart);
			}
			isActive = !isActive;
			break;
		case OnButtonDiscoverClick:
		{
			isDiscovering = !isDiscovering;
			if(isDiscovering)
				readThread = CreateThread(NULL, 0, ThreadDiscover, NULL, 0, NULL);
			else {
				if (readThread) {
					isDiscovering = false;
					WaitForSingleObject(readThread, INFINITE);
					CloseHandle(readThread);
					readThread = NULL;
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
		break;
	}
	case WM_CTLCOLORSTATIC: {
		HDC hdcStatic = (HDC)wp;
		HWND hStatic = (HWND)lp;

		if (hStatic == ActiveControlTextStatus) {
			SetTextColor(hdcStatic, ActiveTextColor);
			SetBkMode(hdcStatic, TRANSPARENT);
			return (LRESULT)GetStockObject(DC_BRUSH);
		}
		else if (hStatic == StatusTextStart) {
			SetTextColor(hdcStatic, ActiveTextColor);
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
		MainWndAddMenus(hWnd);
		MainWndWidgets(hWnd);
		break;
	case WM_DESTROY:
		ExitSoftware();

	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
}
void MainWndAddMenus(HWND hWnd) {
}
void MainWndWidgets(HWND hWnd) {
	StatusTextStart = CreateWindowA("static", "Status: ", WS_VISIBLE | WS_CHILD | ES_CENTER, 50, 50, 50, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(255, 0, 0), StatusTextStart);
	ActiveControlTextStatus = CreateWindowA("static", "inActive", WS_VISIBLE | WS_CHILD | ES_CENTER, 100, 50, 50, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(255, 0, 0), ActiveControlTextStatus);

	DiscoverStatusText = CreateWindowA("static", "0%", WS_VISIBLE | WS_CHILD | ES_CENTER, 200, 110, 50, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), DiscoverStatusText);

	CreateWindowA("button", "Start", WS_VISIBLE | WS_CHILD, 200, 30, 100, 40, hWnd, (HMENU)OnButtonStartClick, NULL, NULL);
	CreateWindowA("button", "Discover", WS_VISIBLE | WS_CHILD, 100, 100, 100, 40, hWnd, (HMENU)OnButtonDiscoverClick, NULL, NULL);
}
void SetActiveTextColor(COLORREF color, HWND ActiveControlText) {
	ActiveTextColor = color;
	InvalidateRect(ActiveControlText, NULL, TRUE);
}