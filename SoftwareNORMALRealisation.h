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

	TempLabel = CreateWindowA("static", " - Hatching Animal", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 550, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryHatchingAnimalColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 547, 25, 25, hWnd, (HMENU)OnButtonHatchingAnimalClick, NULL, NULL);
	//
	TempLabel = CreateWindowA("static", " - Leafcutter ant", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 580, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDiscoveryAntAlayerColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 577, 25, 25, hWnd, (HMENU)OnButtonAntSlayerClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Feed animal", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 610, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	ButtonDIscoveryAnimalCormColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 607, 25, 25, hWnd, (HMENU)OnButtonAnimalCormClick, NULL, NULL);
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
bool Set1HexagonConstruction(int targetI, int targetJ) {
	if (!CheckIfAvailableFor1Hexagon(targetI, targetJ))
		return false;
	if (targetI != -1 && targetJ != -1) {
		COLORREF tempColor = homeMap[targetI][targetJ].color;
		homeMap[targetI][targetJ].color = CurrentDiscoveringColor;

		switch (CurrentDiscoveringColor) {
		case AntSlayerColor: QuantityOfAntSlayerBuilding++; break;
		case AnimalCormColor: QuantityOfAnimalCormBuilding++; break;
		}

		return true;
	}
	return false;
}
bool Set3HexagonConstruction(int targetI, int targetJ) {
	if (!CheckIfGather3Hexagon(targetI, targetJ)) 
		return false;
	
	if (targetI != -1 && targetJ != -1) {
		if (targetI % 2 == 0) {
			homeMap[targetI][targetJ].color = CurrentDiscoveringColor;
			homeMap[targetI][targetJ - 1].color = CurrentDiscoveringColor;
			homeMap[targetI - 1][targetJ].color = CurrentDiscoveringColor;
		}
		else {
			homeMap[targetI][targetJ].color = CurrentDiscoveringColor;
			homeMap[targetI][targetJ - 1].color = CurrentDiscoveringColor;
			homeMap[targetI - 1][targetJ - 1].color = CurrentDiscoveringColor;
		}

		switch (CurrentDiscoveringColor) {
		case ShootersColor: ShooterHexagons=true; break;
		case GuardianColor: GuardianHexagons=true; break;
		case CarriersColor: CarrierHexagons=true; break;
		case EateColor: EateHexagons=true; break;
		case MeteoritColor: MeteoritHexagons=true; break;
		case CrystalHoleColor: CrystalHoleHexagons = true; break;
		case VirusesColor: VirusesHexagons = true; break;
		case EvolutionsColor: EvolutionsHexagons = true; break;
		case OrdinaryCaveColor: OrdinaryCaveHexagons = true; break;
		case WildAnimalBaseColor: WildAnimalHexagons = true; break;
		case RuralContestsColor: RuralContestHexagons = true; break;
		case LadybugColor: LadybugHexagons = true; break;
		case ShellColor: ShellHexagons = true; break;
		case FabricResourcesColor: FabricResourcesHexagons = true; break;
		case WarCaveColor: WarCaveHexagons = true; break;
		case HatchingAnimalColor: QuantityOfHatchingAnimalsBuilding++; break;
		}
		return true;
	}
	return false;
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

	if ((CurrentDiscoveringColor == AntSlayerColor && homeMap[targetI][targetJ].color == BaseDiscoveringColor) || 
		(CurrentDiscoveringColor == AnimalCormColor && homeMap[targetI][targetJ].color == BaseDiscoveringColor) ||
		(CurrentDiscoveringColor == BaseDiscoveringColor && homeMap[targetI][targetJ].color == AntSlayerColor) ||
		(CurrentDiscoveringColor == BaseDiscoveringColor && homeMap[targetI][targetJ].color == AnimalCormColor)){
		if (!Set1HexagonConstruction(targetI, targetJ)) return;
	}
	else {
		if (!Set3HexagonConstruction(targetI, targetJ)) return;
	}
	InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
}
void ChangeBoolPropertyInHexagon(COLORREF HexagonColor) {
	switch (HexagonColor) {
	case ShootersColor: ShooterHexagons = !ShooterHexagons; break;
	case GuardianColor: GuardianHexagons = !GuardianHexagons; break;
	case CarriersColor: CarrierHexagons = !CarrierHexagons; break;
	case EateColor: EateHexagons = !EateHexagons; break;
	case MeteoritColor: MeteoritHexagons = !MeteoritHexagons; break;
	case CrystalHoleColor: CrystalHoleHexagons = !CrystalHoleHexagons; break;
	case VirusesColor: VirusesHexagons = !VirusesHexagons; break;
	case EvolutionsColor: EvolutionsHexagons = !EvolutionsHexagons; break;
	case OrdinaryCaveColor: OrdinaryCaveHexagons = !OrdinaryCaveHexagons; break;
	case WildAnimalBaseColor: WildAnimalHexagons = !WildAnimalHexagons; break;
	case RuralContestsColor: RuralContestHexagons = !RuralContestHexagons; break;
	case LadybugColor: LadybugHexagons = !LadybugHexagons; break;
	case ShellColor: ShellHexagons = !ShellHexagons; break;
	case FabricResourcesColor: FabricResourcesHexagons = !FabricResourcesHexagons; break;
	case WarCaveColor: WarCaveHexagons = !WarCaveHexagons; break;
	case HatchingAnimalColor: QuantityOfHatchingAnimalsBuilding--;
	}
}
bool CheckIfAvailableFor1Hexagon(int IndexI, int IndexJ) {
	if (CurrentDiscoveringColor == BaseDiscoveringColor) {
		if (homeMap[IndexI][IndexJ].color != BaseDiscoveringColor) {
			switch (homeMap[IndexI][IndexJ].color) {
			case AntSlayerColor: QuantityOfAntSlayerBuilding--; break;
			case AnimalCormColor: QuantityOfAnimalCormBuilding--; break;
			}
			homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
			InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
			return false;
		}
	}
	if (IndexJ == 0) return false;

	switch (CurrentDiscoveringColor) {
	case AntSlayerColor: if (QuantityOfAntSlayerBuilding >= 8) return false; break;
	case AnimalCormColor: if (QuantityOfAnimalCormBuilding >= 6) return false; break;
	}

	if (homeMap[IndexI][IndexJ].color == BaseDiscoveringColor)
		return true;
	return false;
}
bool CheckIfGather3Hexagon(int IndexI, int IndexJ) {
	if (CurrentDiscoveringColor == BaseDiscoveringColor) {
		if (homeMap[IndexI][IndexJ].color != BaseDiscoveringColor) {
			if (IndexI % 2 == 0) {
				if (homeMap[IndexI][IndexJ].color == homeMap[IndexI][IndexJ - 1].color && homeMap[IndexI][IndexJ].color == homeMap[IndexI - 1][IndexJ].color) {
					ChangeBoolPropertyInHexagon(homeMap[IndexI][IndexJ].color);
					homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI][IndexJ - 1].color = BaseDiscoveringColor;
					homeMap[IndexI - 1][IndexJ].color = BaseDiscoveringColor;
					InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
					return false;
				}
				else if (homeMap[IndexI][IndexJ].color == homeMap[IndexI - 1][IndexJ + 1].color && homeMap[IndexI][IndexJ].color == homeMap[IndexI][IndexJ + 1].color) {
					ChangeBoolPropertyInHexagon(homeMap[IndexI][IndexJ].color);
					homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI - 1][IndexJ + 1].color = BaseDiscoveringColor;
					homeMap[IndexI][IndexJ + 1].color = BaseDiscoveringColor;
					InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
					return false;
				}
				else if (homeMap[IndexI][IndexJ].color == homeMap[IndexI + 1][IndexJ + 1].color && homeMap[IndexI][IndexJ].color == homeMap[IndexI + 1][IndexJ].color) {
					ChangeBoolPropertyInHexagon(homeMap[IndexI][IndexJ].color);
					homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI + 1][IndexJ + 1].color = BaseDiscoveringColor;
					homeMap[IndexI + 1][IndexJ].color = BaseDiscoveringColor;
					InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
					return false;
				}
			}
			else {
				if (homeMap[IndexI][IndexJ].color == homeMap[IndexI][IndexJ - 1].color && homeMap[IndexI][IndexJ].color == homeMap[IndexI - 1][IndexJ - 1].color) {
					ChangeBoolPropertyInHexagon(homeMap[IndexI][IndexJ].color);
					homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI][IndexJ - 1].color = BaseDiscoveringColor;
					homeMap[IndexI - 1][IndexJ - 1].color = BaseDiscoveringColor;
					InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
					return false;
				}
				else if (homeMap[IndexI][IndexJ].color == homeMap[IndexI - 1][IndexJ].color && homeMap[IndexI][IndexJ].color == homeMap[IndexI][IndexJ + 1].color) {
					ChangeBoolPropertyInHexagon(homeMap[IndexI][IndexJ].color);
					homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI - 1][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI][IndexJ + 1].color = BaseDiscoveringColor;
					InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
					return false;
				}
				else if (homeMap[IndexI][IndexJ].color == homeMap[IndexI + 1][IndexJ].color && homeMap[IndexI][IndexJ].color == homeMap[IndexI + 1][IndexJ - 1].color) {
					ChangeBoolPropertyInHexagon(homeMap[IndexI][IndexJ].color);
					homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI + 1][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI + 1][IndexJ - 1].color = BaseDiscoveringColor;
					InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
					return false;
				}
			}
		}
	}
	if (IndexJ == 0) return false;

	switch (CurrentDiscoveringColor) {
	case ShootersColor: if(ShooterHexagons) return false; break;
	case GuardianColor: if(GuardianHexagons) return false; break;
	case CarriersColor: if(CarrierHexagons) return false; break;
	case EateColor: if (EateHexagons) return false; break;
	case MeteoritColor: if (MeteoritHexagons) return false; break;
	case CrystalHoleColor: if (CrystalHoleHexagons) return false; break;
	case VirusesColor: if (VirusesHexagons) return false; break;
	case EvolutionsColor: if (EvolutionsHexagons) return false; break;
	case OrdinaryCaveColor: if (OrdinaryCaveHexagons) return false; break;
	case WildAnimalBaseColor: if (WildAnimalHexagons) return false; break;
	case RuralContestsColor: if (RuralContestHexagons) return false; break;
	case LadybugColor: if (LadybugHexagons) return false; break;
	case ShellColor: if (ShellHexagons) return false; break;
	case FabricResourcesColor: if (FabricResourcesHexagons) return false; break;
	case WarCaveColor: if (WarCaveHexagons) return false; break;
	case HatchingAnimalColor: if (QuantityOfHatchingAnimalsBuilding >= 4) return false; break;
	}

	if (IndexI % 2 == 0) {
		if ((homeMap[IndexI][IndexJ].color == BaseDiscoveringColor) &&
			(homeMap[IndexI][IndexJ - 1].color == BaseDiscoveringColor) &&
			(homeMap[IndexI - 1][IndexJ].color == BaseDiscoveringColor))
			return true;
		return false;
	}
	else {
		if ((homeMap[IndexI][IndexJ].color == BaseDiscoveringColor) &&
			(homeMap[IndexI][IndexJ - 1].color == BaseDiscoveringColor) &&
			(homeMap[IndexI - 1][IndexJ - 1].color == BaseDiscoveringColor))
			return true;
		return false;
	}
}