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
		CloseHandle(readTime);
		readTime = NULL;
	}

	PostQuitMessage(0);
}
void ExitDiscoveringSoftware(void) {
	PostQuitMessage(0);
}
void DiscoveringWndWidgets(HWND hWnd) {
	HWND CurColorLabel = CreateWindowA("static", "Current color: ", WS_VISIBLE | WS_CHILD | ES_CENTER, 750, 20, 100, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0,0,0), CurColorLabel);
	ButtonDiscoveryCurrentColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 850, 17, 25, 25, hWnd, (HMENU)OnButtonCurrentColor, NULL, NULL);

	HWND BaseColorLabel = CreateWindowA("static", " - Base color", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 70, 100, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), BaseColorLabel);
	ButtonDiscoveryBaseColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 67, 25, 25, hWnd, (HMENU)OnButtonBaseColorClick, NULL, NULL);

	HWND ShootersColorLabel = CreateWindowA("static", " - Shooters", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 100, 100, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), ShootersColorLabel);
	ButtonDiscoveryShootersColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 97, 25, 25, hWnd, (HMENU)OnButtonShootersClick, NULL, NULL);

	HWND GuardiansColorLabel = CreateWindowA("static", " - Guardians", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 130, 100, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), GuardiansColorLabel);
	ButtonDiscoveryGuardiansColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 127, 25, 25, hWnd, (HMENU)OnButtonGuardiansClick, NULL, NULL);

	HWND CurriersColorLabel = CreateWindowA("static", " - Carriers", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 160, 100, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), CurriersColorLabel);
	ButtonDiscoveryCarriersColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 157, 25, 25, hWnd, (HMENU)OnButtonCarriersClick, NULL, NULL);
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
void CreateDiscoveringMap(HWND hWnd) {
	int cenX = 21, cenY = 25, rad = 10;
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			homeMap[i][j].centerX = cenX;
			homeMap[i][j].centerY = cenY;
			homeMap[i][j].radius = rad;
			if ((i == 15 && (j >= 16 && j <= 18)) ||
				(i == 16 && (j >= 15 && j <= 18)) ||
				(i == 17 && (j >= 15 && j <= 19)) ||
				(i == 18 && (j >= 15 && j <= 18)) ||
				(i == 19 && (j >= 16 && j <= 18))) {
				homeMap[i][j].color = RGB(255, 255, 51);
			}
			else {
				homeMap[i][j].color = RGB(192, 192, 192);
			}
			cenX += 20;
		}
		cenY += 20;
		cenX = (i % 2 != 0) ? 21 : 13;
	}
}
void SetNeededColor(int x, int y) {
	const int MAP_SIZE = 35;

	float nearestDefination = 1000000.0f; 
	int targetI = -1;
	int targetJ = -1;


	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if ((i == 15 && (j >= 16 && j <= 18)) ||
				(i == 16 && (j >= 15 && j <= 18)) ||
				(i == 17 && (j >= 15 && j <= 19)) ||
				(i == 18 && (j >= 15 && j <= 18)) ||
				(i == 19 && (j >= 16 && j <= 18))) {
				continue;
			}

			float currentDefination = std::sqrt(
				(std::pow((float)x - homeMap[i][j].centerX, 2) +
					std::pow((float)y - homeMap[i][j].centerY, 2))
			);

			if (currentDefination < nearestDefination) {
				nearestDefination = currentDefination;
				targetI = i;
				targetJ = j;
			}
		}
	}
	switch (CurrentDiscoveringColor) {
	case ShootersColor: if (!CheckIfGather3Hexagon(targetI, targetJ, ShooterHexagons)) return; break;
	case GuardianColor: if (!CheckIfGather3Hexagon(targetI, targetJ, GuardianHexagons)) return; break;
	case CarriersColor: if (!CheckIfGather3Hexagon(targetI, targetJ, CarrierHexagons)) return; break;
	}
	
	if (targetI != -1 && targetJ != -1) {
		COLORREF tempColor = homeMap[targetI][targetJ].color;
		homeMap[targetI][targetJ].color = CurrentDiscoveringColor;

		switch (CurrentDiscoveringColor) {
		case ShootersColor: ShooterHexagons++; break;
		case GuardianColor: GuardianHexagons++; break;
		case CarriersColor: CarrierHexagons++; break;
		}

		switch (tempColor) {
		case ShootersColor: ShooterHexagons--; break;
		case GuardianColor: GuardianHexagons--; break;
		case CarriersColor: CarrierHexagons--; break;
		}
	}
	InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
}
bool CheckIfGather3Hexagon(int IndexI, int IndexJ, int QuantityOfBuilding) {
	if (QuantityOfBuilding == 0)
		return true;
	else if (QuantityOfBuilding == 1) {
		if (IndexI % 2 != 0) {
			if (homeMap[IndexI][IndexJ - 1].color == CurrentDiscoveringColor ||
				homeMap[IndexI - 1][IndexJ - 1].color == CurrentDiscoveringColor ||
				homeMap[IndexI - 1][IndexJ].color == CurrentDiscoveringColor ||
				homeMap[IndexI][IndexJ + 1].color == CurrentDiscoveringColor ||
				homeMap[IndexI + 1][IndexJ].color == CurrentDiscoveringColor ||
				homeMap[IndexI + 1][IndexJ - 1].color == CurrentDiscoveringColor)
				return true;
			return false;
		}
		else {
			if (homeMap[IndexI][IndexJ - 1].color == CurrentDiscoveringColor ||
				homeMap[IndexI - 1][IndexJ].color == CurrentDiscoveringColor ||
				homeMap[IndexI - 1][IndexJ + 1].color == CurrentDiscoveringColor ||
				homeMap[IndexI][IndexJ + 1].color == CurrentDiscoveringColor ||
				homeMap[IndexI + 1][IndexJ + 1].color == CurrentDiscoveringColor ||
				homeMap[IndexI + 1][IndexJ].color == CurrentDiscoveringColor)
				return true;
			return false;
		}
	}
	else if (QuantityOfBuilding == 2) {
		if (IndexI % 2 != 0) {
			if ((homeMap[IndexI][IndexJ - 1].color == CurrentDiscoveringColor &&
				homeMap[IndexI - 1][IndexJ - 1].color == CurrentDiscoveringColor) ||
				(homeMap[IndexI - 1][IndexJ].color == CurrentDiscoveringColor &&
				homeMap[IndexI][IndexJ + 1].color == CurrentDiscoveringColor) ||
				(homeMap[IndexI + 1][IndexJ - 1].color == CurrentDiscoveringColor &&
				homeMap[IndexI + 1][IndexJ].color == CurrentDiscoveringColor))
				return true;
			return false;
		}
		else {
			if ((homeMap[IndexI][IndexJ - 1].color == CurrentDiscoveringColor &&
				homeMap[IndexI - 1][IndexJ].color == CurrentDiscoveringColor) ||
				(homeMap[IndexI - 1][IndexJ + 1].color == CurrentDiscoveringColor &&
				homeMap[IndexI][IndexJ + 1].color == CurrentDiscoveringColor) ||
				(homeMap[IndexI + 1][IndexJ].color == CurrentDiscoveringColor &&
				homeMap[IndexI + 1][IndexJ + 1].color == CurrentDiscoveringColor))
				return true;
			return false;
		}
	}
	else return false;
}