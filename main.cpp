#include "SoftwareDefinitions.h"
#include "SoftwareWINRealisation.h"
#include "SoftwareNORMALRealisation.h"

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

LRESULT CALLBACK SoftwareDiscoveringProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case OnButtonBaseColorClick:
			CurrentDiscoveringColor = BaseDiscoveringColor;
			InvalidateRect(GetDlgItem(hWnd, OnButtonCurrentColor), NULL, TRUE);
			break;
		case OnButtonShootersClick:
			CurrentDiscoveringColor = ShootersColor;
			InvalidateRect(GetDlgItem(hWnd, OnButtonCurrentColor),NULL, TRUE);
			break;
		case OnButtonGuardiansClick:
			CurrentDiscoveringColor = GuardianColor;
			InvalidateRect(GetDlgItem(hWnd, OnButtonCurrentColor), NULL, TRUE);
			break;

		case OnButtonCarriersClick:
			CurrentDiscoveringColor = CarriersColor;
			InvalidateRect(GetDlgItem(hWnd, OnButtonCurrentColor), NULL, TRUE);
			break;
		}
		break;
	case WM_CTLCOLORSTATIC: {
		HDC hdcStatic = (HDC)wp;
		HWND hStatic = (HWND)lp;

		SetTextColor(hdcStatic, RGB(0, 0, 0));
		SetBkMode(hdcStatic, TRANSPARENT);
		return (LRESULT)GetStockObject(DC_BRUSH);

		break;
	}
	case WM_LBUTTONDOWN: {
		int mouseX = GET_X_LPARAM(lp);
		int mouseY = GET_Y_LPARAM(lp);
		if ((mouseX >= 0 && mouseX <= 730) && (mouseY >= 0 && mouseY <= 760)) {
			SetNeededColor(mouseX, mouseY);
		}
		break;
		
	}
	case WM_DRAWITEM: {
		LPDRAWITEMSTRUCT pdis = (LPDRAWITEMSTRUCT)lp;
		switch (pdis->CtlID) {
		case OnButtonBaseColorClick: {
			HDC hdc = pdis->hDC;
			RECT rect = pdis->rcItem;
			COLORREF bgColor = BaseDiscoveringColor;
			HBRUSH hBrush = CreateSolidBrush(bgColor);
			FillRect(hdc, &rect, hBrush);
			DeleteObject(hBrush);
			return TRUE;
			break;
		}
		case OnButtonCurrentColor: {
			HDC hdc = pdis->hDC;
			RECT rect = pdis->rcItem;
			COLORREF bgColor = CurrentDiscoveringColor;
			HBRUSH hBrush = CreateSolidBrush(bgColor);
			FillRect(hdc, &rect, hBrush);
			DeleteObject(hBrush);
			return TRUE;
			break;
		}
		case OnButtonShootersClick: {
			HDC hdc = pdis->hDC;
			RECT rect = pdis->rcItem;
			COLORREF bgColor = ShootersColor;
			HBRUSH hBrush = CreateSolidBrush(bgColor);
			FillRect(hdc, &rect, hBrush);
			DeleteObject(hBrush);
			return TRUE;
			break;
		}
		case OnButtonGuardiansClick: {
			HDC hdc = pdis->hDC;
			RECT rect = pdis->rcItem;
			COLORREF bgColor = GuardianColor;
			HBRUSH hBrush = CreateSolidBrush(bgColor);
			FillRect(hdc, &rect, hBrush);
			DeleteObject(hBrush);
			return TRUE;
			break;
		}
		case OnButtonCarriersClick: {
			HDC hdc = pdis->hDC;
			RECT rect = pdis->rcItem;
			COLORREF bgColor = CarriersColor;
			HBRUSH hBrush = CreateSolidBrush(bgColor);
			FillRect(hdc, &rect, hBrush);
			DeleteObject(hBrush);
			return TRUE;
			break;
		}
		}
		break;
	}
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		HBRUSH hHexagonBrush;
		HBRUSH hOldBrush;

		HPEN hBlackPen = CreatePen(PS_SOLID, 2, RGB(224, 224, 224));
		HPEN hOldPen = (HPEN)SelectObject(hdc, hBlackPen);

		POINT vertices[6];
		int centerX = 21, centerY = 25, radius = 10;
		for (int q = 0; q < 35; q++) {
			for (int j = 0; j < 35; j++) {
				for (int i = 0; i < 6; i++) {
					double startAngle = 90.0;
					double angleDegrees = startAngle + (double)i * 60.0;
					double angleRadians = angleDegrees * M_PI / 180.0;
					vertices[i].x = (LONG)(homeMap[q][j].centerX + homeMap[q][j].radius * cos(angleRadians));
					vertices[i].y = (LONG)(homeMap[q][j].centerY + homeMap[q][j].radius * sin(angleRadians));
				}
				hHexagonBrush = CreateSolidBrush(homeMap[q][j].color);
				hOldBrush = (HBRUSH)SelectObject(hdc, hHexagonBrush);
				Polygon(hdc, vertices, 6);
				SelectObject(hdc, hOldBrush);
				DeleteObject(hHexagonBrush);
			}
		}
		SelectObject(hdc, hOldPen);

		DeleteObject(hBlackPen);

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_CREATE:
		g_hDiscoveringWnd = hWnd;
		CurrentDiscoveringColor = BaseDiscoveringColor;
		DiscoveringWndWidgets(hWnd);
		CreateDiscoveringMap(hWnd);
		InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
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
