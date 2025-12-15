#pragma once
void ExitSoftware(void) {
	THEMEWINDOWCOLOR->unused;
	if (readKey) {
		isProgramWork = false;
		WaitForSingleObject(readKey, INFINITE);
		CloseHandle(readKey);
		readKey = NULL;
	}
	if (readNewWindow) {
		isDiscovering = false;
		WaitForSingleObject(readNewWindow, INFINITE);
		CloseHandle(readNewWindow);
		readNewWindow = NULL;
	}
	if (readTime) {
		isActive = false;
		WaitForSingleObject(readTime, INFINITE);
		CloseHandle(readTime);
		readTime = NULL;
	}

	PostQuitMessage(0);
}
void ExitDiscoveringSoftware(void) {
	PostQuitMessage(0);
}
void DiscoveringWndWidgets(HWND hWnd) {
	
}
void MainWndAddMenus(HWND hWnd) {
}
void MainWndWidgets(HWND hWnd) {
	StatusTextStart = CreateWindowA("static", "Status: ", WS_VISIBLE | WS_CHILD | ES_CENTER, 50, 50, 50, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(255, 0, 0), StatusTextStart);
	ActiveControlTextStatus = CreateWindowA("static", "inActive", WS_VISIBLE | WS_CHILD | ES_CENTER, 100, 50, 50, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(255, 0, 0), ActiveControlTextStatus);

	StatusTextTime = CreateWindowA("static", "Time: ", WS_VISIBLE | WS_CHILD | ES_CENTER, 200, 50, 50, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(255, 0, 0), StatusTextTime);
	ActiveControlTextStatusTime = CreateWindowA("static", "0", WS_VISIBLE | WS_CHILD | ES_CENTER, 250, 50, 100, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(255, 0, 0), ActiveControlTextStatusTime);

	CreateWindowA("button", "Discover", WS_VISIBLE | WS_CHILD, 100, 100, 100, 40, hWnd, (HMENU)OnButtonDiscoverClick, NULL, NULL);
}
void SetActiveTextColor(COLORREF color, HWND ActiveControlText) {
	ActiveTextColor = color;
	InvalidateRect(ActiveControlText, NULL, TRUE);
}

DWORD WINAPI ReadKeysInput(LPVOID lpParameter) {
	INT16 OneAct = 0, ZeroAct = 0;
	while (isProgramWork) {
		short res = GetKeyState(VK_F1);
		if (res == 1 && OneAct == 0) {
			OneAct++;
			PostMessageA(g_hMainWnd, WM_TIME_PROGRESS, res, 0);
			ZeroAct = 1;
		}
		else if (res == 0 && ZeroAct == 1) {
			ZeroAct++;
			PostMessageA(g_hMainWnd, WM_TIME_PROGRESS, res, 0);
			OneAct = 0;
		}
		
		Sleep(100);
	}
	return 0;
}
DWORD WINAPI ThreadDiscover(LPVOID lpParameter) {
	MSG SoftwareDiscoveringMessage = { 0 };

	CreateWindow(L"DiscoveringWndClass", L"Your Base Map", WS_OVERLAPPEDWINDOW | WS_VISIBLE | ES_AUTOVSCROLL | WS_EX_CLIENTEDGE | WS_EX_TOPMOST, 200, 200, 500, 500, NULL, NULL, NULL, NULL);
	while (GetMessageW(&SoftwareDiscoveringMessage, NULL, NULL, NULL) && isDiscovering) {
		TranslateMessage(&SoftwareDiscoveringMessage);
		DispatchMessage(&SoftwareDiscoveringMessage);
	}
	ExitDiscoveringSoftware();

	return 0;
}
DWORD WINAPI ThreadTimeProgres(LPVOID lpParameter) {

	std::string textTime = "";
	while (isActive) {
		Sleep(1000);
		SecondsWordProgram++;

		if (SecondsWordProgram >= 60) {
			SecondsWordProgram = 0;
			MinutesWordProgram++;
		}

		if (MinutesWordProgram >= 60) {
			MinutesWordProgram = 0;
			HoursWordProgram++;
		}

		std::string textTime =
			(HoursWordProgram < 10 ? "0" : "") + std::to_string(HoursWordProgram) + ":" +
			(MinutesWordProgram < 10 ? "0" : "") + std::to_string(MinutesWordProgram) + ":" +
			(SecondsWordProgram < 10 ? "0" : "") + std::to_string(SecondsWordProgram);
		SetWindowTextA(ActiveControlTextStatusTime, textTime.c_str());
	}
	return 0;
}