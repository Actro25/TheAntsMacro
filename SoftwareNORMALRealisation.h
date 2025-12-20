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
	Shooters::ButtonDiscoveryShootersColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 97, 25, 25, hWnd, (HMENU)OnButtonShootersClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Guardians", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 130, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	Guardians::ButtonDiscoveryGuardiansColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 127, 25, 25, hWnd, (HMENU)OnButtonGuardiansClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Carriers", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 160, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	Carriers::ButtonDiscoveryCarriersColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 157, 25, 25, hWnd, (HMENU)OnButtonCarriersClick, NULL, NULL);
	
	TempLabel = CreateWindowA("static", " - Water(Eate)", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 190, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	Eaters::ButtonDiscoveryEateColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 187, 25, 25, hWnd, (HMENU)OnButtonEateClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Meteorit Construction", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 220, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	Meteorites::ButtonDiscoveryMeteoritColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 217, 25, 25, hWnd, (HMENU)OnButtonMeteoritClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Crystale Cave", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 250, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	CrystalHoles::ButtonDiscoveryCrystalHoleColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 247, 25, 25, hWnd, (HMENU)OnButtonCrystalHoleClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Viruses", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 280, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	Viruses::ButtonDiscoveryVirusesColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 277, 25, 25, hWnd, (HMENU)OnButtonVirusesClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Evolutions", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 310, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	Evolutions::ButtonDiscoveryEvolutionsColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 307, 25, 25, hWnd, (HMENU)OnButtonEvolutionClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Ordinary Cave", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 340, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	OrdinaryCaves::ButtonDiscoveryOrdinaryCaveColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 337, 25, 25, hWnd, (HMENU)OnButtonCavesClick, NULL, NULL);
	
	TempLabel = CreateWindowA("static", " - Wild Animals", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 370, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	WildAnimals::ButtonDiscoveryWildAnimalColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 367, 25, 25, hWnd, (HMENU)OnButtonWildAnimalClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Rural Contests", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 400, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	RuralContests::ButtonDiscoveryRuralContestColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 397, 25, 25, hWnd, (HMENU)OnButtonRuralContestClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Ladybug", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 430, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	Ladybugs::ButtonDiscoveryLadybugColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 427, 25, 25, hWnd, (HMENU)OnButtonLadybugClick, NULL, NULL);
	
	TempLabel = CreateWindowA("static", " - Shell Dissolve", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 460, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	Shells::ButtonDiscoveryShellColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 457, 25, 25, hWnd, (HMENU)OnButtonShellClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Fabric Resources", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 490, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	FabricResources::ButtonDiscoveryFabricResourcesColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 487, 25, 25, hWnd, (HMENU)OnButtonFabricResources, NULL, NULL);

	TempLabel = CreateWindowA("static", " - War Cave", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 520, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	WarCaves::ButtonDiscoveryWarCaveColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 517, 25, 25, hWnd, (HMENU)OnButtonWarCaveClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Hatching Animal", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 550, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	HatchingAnimals::ButtonDiscoveryHatchingAnimalColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 547, 25, 25, hWnd, (HMENU)OnButtonHatchingAnimalClick, NULL, NULL);
	
	TempLabel = CreateWindowA("static", " - Leafcutter ant", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 580, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	AntSlayers::ButtonDiscoveryAntSlayerColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 577, 25, 25, hWnd, (HMENU)OnButtonAntSlayerClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Feed animal", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 610, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	AnimalCorms::ButtonDiscoveryAnimalCormColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 607, 25, 25, hWnd, (HMENU)OnButtonAnimalCormClick, NULL, NULL);
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
		case AntSlayers::AntSlayerColor: AntSlayers::QuantityOfAntSlayerBuilding++; break;
		case AnimalCorms::AnimalCormColor: AnimalCorms::QuantityOfAnimalCormBuilding++; break;
		}

		return true;
	}
	return false;
}
void ReckonIncenter3HExagonBuild(int targetI1, int targetJ1, int targetI2, int targetJ2, int targetI3, int targetJ3) {
	float x1 = 0, y1 = 0, A=0,B=0,C=0;
	A = std::sqrt((std::pow((float)homeMap[targetI1][targetJ1].centerX - homeMap[targetI2][targetJ2].centerX, 2) +
			std::pow((float)homeMap[targetI1][targetJ1].centerY - homeMap[targetI2][targetJ2].centerY, 2)));
	B = std::sqrt((std::pow((float)homeMap[targetI2][targetJ2].centerX - homeMap[targetI3][targetJ3].centerX, 2) +
			std::pow((float)homeMap[targetI2][targetJ2].centerY - homeMap[targetI3][targetJ3].centerY, 2)));
	C = std::sqrt((std::pow((float)homeMap[targetI3][targetJ3].centerX - homeMap[targetI1][targetJ1].centerX, 2) +
			std::pow((float)homeMap[targetI3][targetJ3].centerY - homeMap[targetI1][targetJ1].centerY, 2)));
	x1 = (B * homeMap[targetI1][targetJ1].centerX + A * homeMap[targetI2][targetJ2].centerX + C * homeMap[targetI3][targetJ3].centerX) / (A + B + C);
	y1 = (B * homeMap[targetI1][targetJ1].centerY + A * homeMap[targetI2][targetJ2].centerY + C * homeMap[targetI3][targetJ3].centerY) / (A + B + C);
}
bool Set3HexagonConstruction(int targetI, int targetJ) {
	if (!CheckIfGather3Hexagon(targetI, targetJ)) 
		return false;
	
	if (targetI != -1 && targetJ != -1) {
		if (targetI % 2 == 0) {
			homeMap[targetI][targetJ].color = CurrentDiscoveringColor;
			homeMap[targetI][targetJ - 1].color = CurrentDiscoveringColor;
			homeMap[targetI - 1][targetJ].color = CurrentDiscoveringColor;
			ReckonIncenter3HExagonBuild(targetI, targetJ, targetI, targetJ-1,targetI-1,targetJ);
		}
		else {
			homeMap[targetI][targetJ].color = CurrentDiscoveringColor;
			homeMap[targetI][targetJ - 1].color = CurrentDiscoveringColor;
			homeMap[targetI - 1][targetJ - 1].color = CurrentDiscoveringColor;
			ReckonIncenter3HExagonBuild(targetI, targetJ, targetI, targetJ - 1, targetI - 1, targetJ - 1);
		}

		switch (CurrentDiscoveringColor) {
		case Shooters::ShootersColor:        Shooters::ShooterHexagons = true; break;
		case Guardians::GuardianColor:      Guardians::GuardianHexagons = true; break;
		case Carriers::CarriersColor:       Carriers::CarrierHexagons = true; break;
		case Eaters::EateColor:             Eaters::EateHexagons = true; break;
		case Meteorites::MeteoritColor:     Meteorites::MeteoritHexagons = true; break;
		case CrystalHoles::CrystalHoleColor: CrystalHoles::CrystalHoleHexagons = true; break;
		case Viruses::VirusesColor:         Viruses::VirusesHexagons = true; break;
		case Evolutions::EvolutionsColor:    Evolutions::EvolutionsHexagons = true; break;
		case OrdinaryCaves::OrdinaryCaveColor: OrdinaryCaves::OrdinaryCaveHexagons = true; break;
		case WildAnimals::WildAnimalBaseColor: WildAnimals::WildAnimalHexagons = true; break;
		case RuralContests::RuralContestsColor: RuralContests::RuralContestHexagons = true; break;
		case Ladybugs::LadybugColor:         Ladybugs::LadybugHexagons = true; break;
		case Shells::ShellColor:             Shells::ShellHexagons = true; break;
		case FabricResources::FabricResourcesColor: FabricResources::FabricResourcesHexagons = true; break;
		case WarCaves::WarCaveColor:         WarCaves::WarCaveHexagons = true; break;
		case HatchingAnimals::HatchingAnimalColor: HatchingAnimals::QuantityOfHatchingAnimalsBuilding++; break;
		default: break;
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

	if ((CurrentDiscoveringColor == AntSlayers::AntSlayerColor && homeMap[targetI][targetJ].color == BaseDiscoveringColor) ||
		(CurrentDiscoveringColor == AnimalCorms::AnimalCormColor && homeMap[targetI][targetJ].color == BaseDiscoveringColor) ||
		(CurrentDiscoveringColor == BaseDiscoveringColor && homeMap[targetI][targetJ].color == AntSlayers::AntSlayerColor) ||
		(CurrentDiscoveringColor == BaseDiscoveringColor && homeMap[targetI][targetJ].color == AnimalCorms::AnimalCormColor)){
		if (!Set1HexagonConstruction(targetI, targetJ)) return;
	}
	else {
		if (!Set3HexagonConstruction(targetI, targetJ)) return;
	}
	InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
}
void ChangeBoolPropertyInHexagon(COLORREF HexagonColor) {
	switch (HexagonColor) {
	case Shooters::ShootersColor:              Shooters::ShooterHexagons = !Shooters::ShooterHexagons; break;
	case Guardians::GuardianColor:            Guardians::GuardianHexagons = !Guardians::GuardianHexagons; break;
	case Carriers::CarriersColor:             Carriers::CarrierHexagons = !Carriers::CarrierHexagons; break;
	case Eaters::EateColor:                   Eaters::EateHexagons = !Eaters::EateHexagons; break;
	case Meteorites::MeteoritColor:           Meteorites::MeteoritHexagons = !Meteorites::MeteoritHexagons; break;
	case CrystalHoles::CrystalHoleColor:      CrystalHoles::CrystalHoleHexagons = !CrystalHoles::CrystalHoleHexagons; break;
	case Viruses::VirusesColor:               Viruses::VirusesHexagons = !Viruses::VirusesHexagons; break;
	case Evolutions::EvolutionsColor:         Evolutions::EvolutionsHexagons = !Evolutions::EvolutionsHexagons; break;
	case OrdinaryCaves::OrdinaryCaveColor:    OrdinaryCaves::OrdinaryCaveHexagons = !OrdinaryCaves::OrdinaryCaveHexagons; break;
	case WildAnimals::WildAnimalBaseColor:    WildAnimals::WildAnimalHexagons = !WildAnimals::WildAnimalHexagons; break;
	case RuralContests::RuralContestsColor:   RuralContests::RuralContestHexagons = !RuralContests::RuralContestHexagons; break;
	case Ladybugs::LadybugColor:              Ladybugs::LadybugHexagons = !Ladybugs::LadybugHexagons; break;
	case Shells::ShellColor:                  Shells::ShellHexagons = !Shells::ShellHexagons; break;
	case FabricResources::FabricResourcesColor: FabricResources::FabricResourcesHexagons = !FabricResources::FabricResourcesHexagons; break;
	case WarCaves::WarCaveColor:              WarCaves::WarCaveHexagons = !WarCaves::WarCaveHexagons; break;
	case HatchingAnimals::HatchingAnimalColor: HatchingAnimals::QuantityOfHatchingAnimalsBuilding--; break;
	default: break;
	}
}
bool CheckIfAvailableFor1Hexagon(int IndexI, int IndexJ) {
	if (CurrentDiscoveringColor == BaseDiscoveringColor) {
		if (homeMap[IndexI][IndexJ].color != BaseDiscoveringColor) {
			switch (homeMap[IndexI][IndexJ].color) {
			case AntSlayers::AntSlayerColor: AntSlayers::QuantityOfAntSlayerBuilding--; break;
			case AnimalCorms::AnimalCormColor: AnimalCorms::QuantityOfAnimalCormBuilding--; break;
			}
			homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
			InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
			return false;
		}
	}
	if (IndexJ == 0) return false;

	switch (CurrentDiscoveringColor) {
	case AntSlayers::AntSlayerColor: if (AntSlayers::QuantityOfAntSlayerBuilding >= 8) return false; break;
	case AnimalCorms::AnimalCormColor: if (AnimalCorms::QuantityOfAnimalCormBuilding >= 6) return false; break;
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
	case Shooters::ShootersColor:               if (Shooters::ShooterHexagons) return false; break;
	case Guardians::GuardianColor:             if (Guardians::GuardianHexagons) return false; break;
	case Carriers::CarriersColor:              if (Carriers::CarrierHexagons) return false; break;
	case Eaters::EateColor:                    if (Eaters::EateHexagons) return false; break;
	case Meteorites::MeteoritColor:            if (Meteorites::MeteoritHexagons) return false; break;
	case CrystalHoles::CrystalHoleColor:       if (CrystalHoles::CrystalHoleHexagons) return false; break;
	case Viruses::VirusesColor:                if (Viruses::VirusesHexagons) return false; break;
	case Evolutions::EvolutionsColor:          if (Evolutions::EvolutionsHexagons) return false; break;
	case OrdinaryCaves::OrdinaryCaveColor:     if (OrdinaryCaves::OrdinaryCaveHexagons) return false; break;
	case WildAnimals::WildAnimalBaseColor:     if (WildAnimals::WildAnimalHexagons) return false; break;
	case RuralContests::RuralContestsColor:    if (RuralContests::RuralContestHexagons) return false; break;
	case Ladybugs::LadybugColor:               if (Ladybugs::LadybugHexagons) return false; break;
	case Shells::ShellColor:                   if (Shells::ShellHexagons) return false; break;
	case FabricResources::FabricResourcesColor: if (FabricResources::FabricResourcesHexagons) return false; break;
	case WarCaves::WarCaveColor:               if (WarCaves::WarCaveHexagons) return false; break;
	case HatchingAnimals::HatchingAnimalColor:  if (HatchingAnimals::QuantityOfHatchingAnimalsBuilding >= 4) return false; break;
	default: break;
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