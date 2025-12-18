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
	HWND TempLabel = CreateWindowA("static", "Current color: ", WS_VISIBLE | WS_CHILD | ES_CENTER, 750, 20, 100, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0,0,0), TempLabel);
	ButtonDiscoveryCurrentColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 850, 17, 25, 25, hWnd, (HMENU)OnButtonCurrentColor, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Base color", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 70, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryBaseColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 67, 25, 25, hWnd, (HMENU)OnButtonBaseColorClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Shooters", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 100, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryShootersColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 97, 25, 25, hWnd, (HMENU)OnButtonShootersClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Guardians", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 130, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryGuardiansColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 127, 25, 25, hWnd, (HMENU)OnButtonGuardiansClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Carriers", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 160, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryCarriersColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 157, 25, 25, hWnd, (HMENU)OnButtonCarriersClick, NULL, NULL);
	
	TempLabel = CreateWindowA("static", " - Water(Eate)", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 190, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryEateColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 187, 25, 25, hWnd, (HMENU)OnButtonEateClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Meteorit Construction", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 220, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryMeteoritColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 217, 25, 25, hWnd, (HMENU)OnButtonMeteoritClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Crystale Cave", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 250, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryCrystalHoleColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 247, 25, 25, hWnd, (HMENU)OnButtonCrystalHoleClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Viruses", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 280, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryVirusesColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 277, 25, 25, hWnd, (HMENU)OnButtonVirusesClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Evolutions", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 310, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryEvolutionsColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 307, 25, 25, hWnd, (HMENU)OnButtonEvolutionClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Ordinary Cave", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 340, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryOrdinaryCaveColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 337, 25, 25, hWnd, (HMENU)OnButtonCavesClick, NULL, NULL);
	
	TempLabel = CreateWindowA("static", " - Wild Animals", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 370, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryWildAnimalColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 367, 25, 25, hWnd, (HMENU)OnButtonWildAnimalClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Rural Contests", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 400, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryRuralContestColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 397, 25, 25, hWnd, (HMENU)OnButtonRuralContestClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Ladybug", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 430, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryLadybugColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 427, 25, 25, hWnd, (HMENU)OnButtonLadybugClick, NULL, NULL);
	//
	TempLabel = CreateWindowA("static", " - Shell Dissolve", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 460, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryShellColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 457, 25, 25, hWnd, (HMENU)OnButtonShellClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Fabric Resources", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 490, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryFabricResourcesColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 487, 25, 25, hWnd, (HMENU)OnButtonFabricResources, NULL, NULL);

	TempLabel = CreateWindowA("static", " - War Cave", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 520, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryWarCaveColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 517, 25, 25, hWnd, (HMENU)OnButtonWarCaveClick, NULL, NULL);
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
	case EateColor: if (!CheckIfGather3Hexagon(targetI, targetJ, EateHexagons)) return; break;
	case MeteoritColor: if (!CheckIfGather3Hexagon(targetI, targetJ, MeteoritHexagons)) return; break;
	case CrystalHoleColor: if (!CheckIfGather3Hexagon(targetI, targetJ, CrystalHoleHexagons)) return; break;
	case VirusesColor: if (!CheckIfGather3Hexagon(targetI, targetJ, VirusesHexagons)) return; break;
	case EvolutionsColor: if (!CheckIfGather3Hexagon(targetI, targetJ, EvolutionsHexagons)) return; break;
	case OrdinaryCaveColor: if (!CheckIfGather3Hexagon(targetI, targetJ, OrdinaryCaveHexagons)) return; break;
	case WildAnimalBaseColor: if (!CheckIfGather3Hexagon(targetI, targetJ, WildAnimalHexagons)) return; break;
	case RuralContestsColor: if (!CheckIfGather3Hexagon(targetI, targetJ, RuralContestHexagons)) return; break;
	case LadybugColor: if (!CheckIfGather3Hexagon(targetI, targetJ, LadybugHexagons)) return; break;
	case ShellColor: if (!CheckIfGather3Hexagon(targetI, targetJ, ShellHexagons)) return; break;
	case FabricResourcesColor: if (!CheckIfGather3Hexagon(targetI, targetJ, FabricResourcesHexagons)) return; break;
	case WarCaveColor: if (!CheckIfGather3Hexagon(targetI, targetJ, WarCaveHexagons)) return; break;
	}
	
	if (targetI != -1 && targetJ != -1) {
		COLORREF tempColor = homeMap[targetI][targetJ].color;
		homeMap[targetI][targetJ].color = CurrentDiscoveringColor;

		switch (CurrentDiscoveringColor) {
		case ShootersColor: ShooterHexagons++; break;
		case GuardianColor: GuardianHexagons++; break;
		case CarriersColor: CarrierHexagons++; break;
		case EateColor: EateHexagons++; break;
		case MeteoritColor: MeteoritHexagons++; break;
		case CrystalHoleColor: CrystalHoleHexagons++; break;
		case VirusesColor: VirusesHexagons++; break;
		case EvolutionsColor: EvolutionsHexagons++; break;
		case OrdinaryCaveColor: OrdinaryCaveHexagons++; break;
		case WildAnimalBaseColor: WildAnimalHexagons++; break;
		case RuralContestsColor: RuralContestHexagons++; break;
		case LadybugColor: LadybugHexagons++; break;
		case ShellColor: ShellHexagons++; break;
		case FabricResourcesColor: FabricResourcesHexagons++; break;
		case WarCaveColor: WarCaveHexagons++; break;
		}

		switch (tempColor) {
		case ShootersColor: ShooterHexagons--; break;
		case GuardianColor: GuardianHexagons--; break;
		case CarriersColor: CarrierHexagons--; break;
		case EateColor: EateHexagons--; break;
		case MeteoritColor: MeteoritHexagons--; break;
		case CrystalHoleColor: CrystalHoleHexagons--; break;
		case VirusesColor: VirusesHexagons--; break;
		case EvolutionsColor: EvolutionsHexagons--; break;
		case OrdinaryCaveColor: OrdinaryCaveHexagons--; break;
		case WildAnimalBaseColor: WildAnimalHexagons--; break;
		case RuralContestsColor: RuralContestHexagons--; break;
		case LadybugColor: LadybugHexagons--; break;
		case ShellColor: ShellHexagons--; break;
		case FabricResourcesColor: FabricResourcesHexagons--; break;
		case WarCaveColor: WarCaveHexagons--; break;
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