#pragma once
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

	CreateWindow(L"DiscoveringWndClass", L"Your Base Map", WS_OVERLAPPEDWINDOW | WS_VISIBLE | ES_AUTOVSCROLL | WS_EX_CLIENTEDGE | WS_EX_TOPMOST, 200, 200, 1000, 760, NULL, NULL, NULL, NULL);
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