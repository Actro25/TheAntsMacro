BuildingStruct shooters = { .Color = COLOR_SHOOTERS, .type = BuildingType::Shooters };
BuildingStruct guardians = { .Color = COLOR_GUARDIANS, .type = BuildingType::Guardians };
BuildingStruct carriers = { .Color = COLOR_CARRIERS, .type = BuildingType::Carriers };
BuildingStruct eaters = { .Color = COLOR_EATERS, .type = BuildingType::Eaters };
BuildingStruct meteorites = { .Color = COLOR_METEORITES, .type = BuildingType::Meteorites };
BuildingStruct crystalHoles = { .Color = COLOR_CRYSTALHOLES, .type = BuildingType::CrystalHoles };
BuildingStruct viruses = { .Color = COLOR_VIRUSES, .type = BuildingType::Viruses };
BuildingStruct evolutions = { .Color = COLOR_EVOLUTIONS, .type = BuildingType::Evolutions };
BuildingStruct ordinaryCaves = { .Color = COLOR_ORDINARYCAVES, .type = BuildingType::OrdinaryCaves };
BuildingStruct wildAnimals = { .Color = COLOR_WILDANIMALS, .type = BuildingType::WildAnimals };
BuildingStruct ruralContests = { .Color = COLOR_RURALCONTESTS, .type = BuildingType::RuralContests };
BuildingStruct ladybugs = { .Color = COLOR_LADYBUGS, .type = BuildingType::Ladybugs };
BuildingStruct shells = { .Color = COLOR_SHELLS, .type = BuildingType::Shells };
BuildingStruct fabricResources = { .Color = COLOR_FABRICRESOURCES, .type = BuildingType::FabricResources };
BuildingStruct warCaves = { .Color = COLOR_WARCAVES, .type = BuildingType::WarCaves };

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
	ExitDiscoveringSoftware();
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
	HWND TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 97, 25, 25, hWnd, (HMENU)OnButtonShootersClick, NULL, NULL);
	shooters.FunctionCreate("Shooters", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Guardians", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 130, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 127, 25, 25, hWnd, (HMENU)OnButtonGuardiansClick, NULL, NULL);
	guardians.FunctionCreate("Guardians", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Carriers", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 160, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 157, 25, 25, hWnd, (HMENU)OnButtonCarriersClick, NULL, NULL);
	carriers.FunctionCreate("Carriers", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Water(Eate)", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 190, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 187, 25, 25, hWnd, (HMENU)OnButtonEateClick, NULL, NULL);
	eaters.FunctionCreate("Water(Eate)", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Meteorit Construction", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 220, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 217, 25, 25, hWnd, (HMENU)OnButtonMeteoritClick, NULL, NULL);
	meteorites.FunctionCreate("Meteorit Construction", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Crystale Cave", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 250, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 247, 25, 25, hWnd, (HMENU)OnButtonCrystalHoleClick, NULL, NULL);
	crystalHoles.FunctionCreate("Crystale Cave", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Viruses", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 280, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 277, 25, 25, hWnd, (HMENU)OnButtonVirusesClick, NULL, NULL);
	viruses.FunctionCreate("Viruses", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Evolutions", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 310, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 307, 25, 25, hWnd, (HMENU)OnButtonEvolutionClick, NULL, NULL);
	evolutions.FunctionCreate("Evolutions", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Ordinary Cave", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 340, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 337, 25, 25, hWnd, (HMENU)OnButtonCavesClick, NULL, NULL);
	ordinaryCaves.FunctionCreate("Ordinary Cave", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Wild Animals", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 370, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 367, 25, 25, hWnd, (HMENU)OnButtonWildAnimalClick, NULL, NULL);
	wildAnimals.FunctionCreate("Wild Animals", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Rural Contests", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 400, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 397, 25, 25, hWnd, (HMENU)OnButtonRuralContestClick, NULL, NULL);
	ruralContests.FunctionCreate("Rural Contests", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Ladybug", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 430, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 427, 25, 25, hWnd, (HMENU)OnButtonLadybugClick, NULL, NULL);
	ladybugs.FunctionCreate("Ladybug", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Shell Dissolve", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 460, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 457, 25, 25, hWnd, (HMENU)OnButtonShellClick, NULL, NULL);
	shells.FunctionCreate("Shell Dissolve", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - Fabric Resources", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 490, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 487, 25, 25, hWnd, (HMENU)OnButtonFabricResources, NULL, NULL);
	fabricResources.FunctionCreate("Fabric Resources", { 0,0 }, false, TempButton);

	TempLabel = CreateWindowA("static", " - War Cave", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 520, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	TempButton = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 517, 25, 25, hWnd, (HMENU)OnButtonWarCaveClick, NULL, NULL);
	warCaves.FunctionCreate("War Cave", { 0,0 }, false, TempButton);


	TempLabel = CreateWindowA("static", " - Hatching Animal", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 550, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	HatchingAnimals::ButtonDiscoveryHatchingAnimalColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 547, 25, 25, hWnd, (HMENU)OnButtonHatchingAnimalClick, NULL, NULL);
	
	TempLabel = CreateWindowA("static", " - Leafcutter ant", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 580, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	AntSlayers::ButtonDiscoveryAntSlayerColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 577, 25, 25, hWnd, (HMENU)OnButtonAntSlayerClick, NULL, NULL);

	TempLabel = CreateWindowA("static", " - Feed animal", WS_VISIBLE | WS_CHILD | ES_CENTER, 770, 610, 150, 50, hWnd, NULL, NULL, NULL);
	SetActiveTextColor(RGB(0, 0, 0), TempLabel);
	AnimalCorms::ButtonDiscoveryAnimalCormColor = CreateWindowA("button", "", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 750, 607, 25, 25, hWnd, (HMENU)OnButtonAnimalCormClick, NULL, NULL);

	DiscoverSaveButton = CreateWindowA("button", "Save", WS_VISIBLE | WS_CHILD, 730, 640, 220, 30, hWnd, (HMENU)OnButtonDiscoverSaveClick, NULL, NULL);
	DiscoverCancelButton = CreateWindowA("button", "Cancel", WS_VISIBLE | WS_CHILD, 730, 680, 220, 30, hWnd, (HMENU)OnButtonDiscoverCancelClick, NULL, NULL);
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
		case AntSlayers::AntSlayerColor: 
			AntSlayers::QuantityOfAntSlayerBuilding++; 
			AntSlayers::incenter.push_back({homeMap[targetI][targetJ].centerX,homeMap[targetI][targetJ].centerY});
			break;
		case AnimalCorms::AnimalCormColor: 
			AnimalCorms::QuantityOfAnimalCormBuilding++; 
			AnimalCorms::incenter.push_back({ homeMap[targetI][targetJ].centerX,homeMap[targetI][targetJ].centerY});
			break;
		}

		return true;
	}
	return false;
}
void ReckonIncenter3HExagonBuild(int targetI1, int targetJ1, int targetI2, int targetJ2, int targetI3, int targetJ3) {
	int x1 = 0, y1 = 0; 
	float A = 0, B = 0, C = 0; 
	POINT F;
	
	A = std::sqrt((std::pow((float)homeMap[targetI1][targetJ1].centerX - homeMap[targetI2][targetJ2].centerX, 2) +
			std::pow((float)homeMap[targetI1][targetJ1].centerY - homeMap[targetI2][targetJ2].centerY, 2)));
	B = std::sqrt((std::pow((float)homeMap[targetI2][targetJ2].centerX - homeMap[targetI3][targetJ3].centerX, 2) +
			std::pow((float)homeMap[targetI2][targetJ2].centerY - homeMap[targetI3][targetJ3].centerY, 2)));
	C = std::sqrt((std::pow((float)homeMap[targetI3][targetJ3].centerX - homeMap[targetI1][targetJ1].centerX, 2) +
			std::pow((float)homeMap[targetI3][targetJ3].centerY - homeMap[targetI1][targetJ1].centerY, 2)));
	x1 = (B * homeMap[targetI1][targetJ1].centerX + A * homeMap[targetI2][targetJ2].centerX + C * homeMap[targetI3][targetJ3].centerX) / (A + B + C);
	y1 = (B * homeMap[targetI1][targetJ1].centerY + A * homeMap[targetI2][targetJ2].centerY + C * homeMap[targetI3][targetJ3].centerY) / (A + B + C);
	F = { x1,y1 };
	if (CurrentDiscoveringColor == HatchingAnimals::HatchingAnimalColor) {
		HatchingAnimals::incenter.push_back(F);
	}
	
	switch (CurrentDiscoveringColor) {
	case COLOR_SHOOTERS:        shooters.incenter = F; break;
	case COLOR_GUARDIANS:       guardians.incenter = F; break;
	case COLOR_CARRIERS:        carriers.incenter = F; break;
	case COLOR_EATERS:          eaters.incenter = F; break;
	case COLOR_METEORITES:      meteorites.incenter = F; break;
	case COLOR_CRYSTALHOLES:    crystalHoles.incenter = F; break;
	case COLOR_VIRUSES:         viruses.incenter = F; break;
	case COLOR_EVOLUTIONS:      evolutions.incenter = F; break;
	case COLOR_ORDINARYCAVES:   ordinaryCaves.incenter = F; break;
	case COLOR_WILDANIMALS:     wildAnimals.incenter = F; break;
	case COLOR_RURALCONTESTS:   ruralContests.incenter = F; break;
	case COLOR_LADYBUGS:        ladybugs.incenter = F; break;
	case COLOR_SHELLS:          shells.incenter = F; break;
	case COLOR_FABRICRESOURCES: fabricResources.incenter = F; break;
	case COLOR_WARCAVES:        warCaves.incenter = F; break;
	default: break;
	}
}
void DeleteReckonIncenter3HExagonBuild(int targetI1, int targetJ1, int targetI2, int targetJ2, int targetI3, int targetJ3, COLORREF col) {
	if (col == HatchingAnimals::HatchingAnimalColor) {
		int x1 = 0, y1 = 0;
		float A = 0, B = 0, C = 0;
		POINT F;

		A = std::sqrt((std::pow((float)homeMap[targetI1][targetJ1].centerX - homeMap[targetI2][targetJ2].centerX, 2) +
			std::pow((float)homeMap[targetI1][targetJ1].centerY - homeMap[targetI2][targetJ2].centerY, 2)));
		B = std::sqrt((std::pow((float)homeMap[targetI2][targetJ2].centerX - homeMap[targetI3][targetJ3].centerX, 2) +
			std::pow((float)homeMap[targetI2][targetJ2].centerY - homeMap[targetI3][targetJ3].centerY, 2)));
		C = std::sqrt((std::pow((float)homeMap[targetI3][targetJ3].centerX - homeMap[targetI1][targetJ1].centerX, 2) +
			std::pow((float)homeMap[targetI3][targetJ3].centerY - homeMap[targetI1][targetJ1].centerY, 2)));
		x1 = (B * homeMap[targetI1][targetJ1].centerX + A * homeMap[targetI2][targetJ2].centerX + C * homeMap[targetI3][targetJ3].centerX) / (A + B + C);
		y1 = (B * homeMap[targetI1][targetJ1].centerY + A * homeMap[targetI2][targetJ2].centerY + C * homeMap[targetI3][targetJ3].centerY) / (A + B + C);
		F = { x1,y1 };
		std::erase_if(HatchingAnimals::incenter, [&](const POINT& c) {
			return c.x == F.x && c.y == F.y;
		});
		return;
	}

	switch (col) {
	case COLOR_SHOOTERS:        shooters.incenter = { 0,0 }; break;
	case COLOR_GUARDIANS:       guardians.incenter = { 0,0 }; break;
	case COLOR_CARRIERS:        carriers.incenter = { 0,0 }; break;
	case COLOR_EATERS:          eaters.incenter = { 0,0 }; break;
	case COLOR_METEORITES:      meteorites.incenter = { 0,0 }; break;
	case COLOR_CRYSTALHOLES:    crystalHoles.incenter = { 0,0 }; break;
	case COLOR_VIRUSES:         viruses.incenter = { 0,0 }; break;
	case COLOR_EVOLUTIONS:      evolutions.incenter = { 0,0 }; break;
	case COLOR_ORDINARYCAVES:   ordinaryCaves.incenter = { 0,0 }; break;
	case COLOR_WILDANIMALS:     wildAnimals.incenter = { 0,0 }; break;
	case COLOR_RURALCONTESTS:   ruralContests.incenter = { 0,0 }; break;
	case COLOR_LADYBUGS:        ladybugs.incenter = { 0,0 }; break;
	case COLOR_SHELLS:          shells.incenter = { 0, 0 }; break;
	case COLOR_FABRICRESOURCES: fabricResources.incenter = { 0,0 }; break;
	case COLOR_WARCAVES:        warCaves.incenter = { 0,0 }; break;
	default: break;
	}
}
void DeleteReckonIncenter1HExagonBuild(int targetI, int targetJ) {
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
		case COLOR_SHOOTERS:        shooters.isPlaced = true; break;
		case COLOR_GUARDIANS:       guardians.isPlaced = true; break;
		case COLOR_CARRIERS:        carriers.isPlaced = true; break;
		case COLOR_EATERS:          eaters.isPlaced = true; break;
		case COLOR_METEORITES:      meteorites.isPlaced = true; break;
		case COLOR_CRYSTALHOLES:    crystalHoles.isPlaced = true; break;
		case COLOR_VIRUSES:         viruses.isPlaced = true; break;
		case COLOR_EVOLUTIONS:      evolutions.isPlaced = true; break;
		case COLOR_ORDINARYCAVES:   ordinaryCaves.isPlaced = true; break;
		case COLOR_WILDANIMALS:     wildAnimals.isPlaced = true; break;
		case COLOR_RURALCONTESTS:   ruralContests.isPlaced = true; break;
		case COLOR_LADYBUGS:        ladybugs.isPlaced = true; break;
		case COLOR_SHELLS:          shells.isPlaced = true; break;
		case COLOR_FABRICRESOURCES: fabricResources.isPlaced = true; break;
		case COLOR_WARCAVES:        warCaves.isPlaced = true; break;

		case HatchingAnimals::HatchingAnimalColor: HatchingAnimals::QuantityOfHatchingAnimalsBuilding++; break;
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
	case COLOR_SHOOTERS:        shooters.isPlaced = !shooters.isPlaced; break;
	case COLOR_GUARDIANS:       guardians.isPlaced = !guardians.isPlaced; break;
	case COLOR_CARRIERS:        carriers.isPlaced = !carriers.isPlaced; break;
	case COLOR_EATERS:          eaters.isPlaced = !eaters.isPlaced; break;
	case COLOR_METEORITES:      meteorites.isPlaced = !meteorites.isPlaced; break;
	case COLOR_CRYSTALHOLES:    crystalHoles.isPlaced = !crystalHoles.isPlaced; break;
	case COLOR_VIRUSES:         viruses.isPlaced = !viruses.isPlaced; break;
	case COLOR_EVOLUTIONS:      evolutions.isPlaced = !evolutions.isPlaced; break;
	case COLOR_ORDINARYCAVES:   ordinaryCaves.isPlaced = !ordinaryCaves.isPlaced; break;
	case COLOR_WILDANIMALS:     wildAnimals.isPlaced = !wildAnimals.isPlaced; break;
	case COLOR_RURALCONTESTS:   ruralContests.isPlaced = !ruralContests.isPlaced; break;
	case COLOR_LADYBUGS:        ladybugs.isPlaced = !ladybugs.isPlaced; break;
	case COLOR_SHELLS:          shells.isPlaced = !shells.isPlaced; break;
	case COLOR_FABRICRESOURCES: fabricResources.isPlaced = !fabricResources.isPlaced; break;
	case COLOR_WARCAVES:        warCaves.isPlaced = !warCaves.isPlaced; break;

	case HatchingAnimals::HatchingAnimalColor: HatchingAnimals::QuantityOfHatchingAnimalsBuilding--; break;
	}
}
bool CheckIfAvailableFor1Hexagon(int IndexI, int IndexJ) {
	if (CurrentDiscoveringColor == BaseDiscoveringColor) {
		if (homeMap[IndexI][IndexJ].color != BaseDiscoveringColor) {
			switch (homeMap[IndexI][IndexJ].color) {
			case AntSlayers::AntSlayerColor: 
				AntSlayers::QuantityOfAntSlayerBuilding--; 
				std::erase_if(AntSlayers::incenter, [&](const POINT& c) {
					return c.x == homeMap[IndexI][IndexJ].centerX && c.y == homeMap[IndexI][IndexJ].centerY;
				});
				break;
			case AnimalCorms::AnimalCormColor: 
				AnimalCorms::QuantityOfAnimalCormBuilding--; 
				std::erase_if(AnimalCorms::incenter, [&](const POINT& c) {
					return c.x == homeMap[IndexI][IndexJ].centerX && c.y == homeMap[IndexI][IndexJ].centerY;
				});
				break;
			}
			DeleteReckonIncenter1HExagonBuild(IndexI,IndexJ);
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
					DeleteReckonIncenter3HExagonBuild(IndexI,IndexJ,IndexI,IndexJ - 1, IndexI - 1, IndexJ, homeMap[IndexI][IndexJ].color);
					homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI][IndexJ - 1].color = BaseDiscoveringColor;
					homeMap[IndexI - 1][IndexJ].color = BaseDiscoveringColor;
					InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
					return false;
				}
				else if (homeMap[IndexI][IndexJ].color == homeMap[IndexI - 1][IndexJ + 1].color && homeMap[IndexI][IndexJ].color == homeMap[IndexI][IndexJ + 1].color) {
					ChangeBoolPropertyInHexagon(homeMap[IndexI][IndexJ].color);
					DeleteReckonIncenter3HExagonBuild(IndexI, IndexJ, IndexI - 1, IndexJ + 1, IndexI, IndexJ + 1, homeMap[IndexI][IndexJ].color);
					homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI - 1][IndexJ + 1].color = BaseDiscoveringColor;
					homeMap[IndexI][IndexJ + 1].color = BaseDiscoveringColor;
					InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
					return false;
				}
				else if (homeMap[IndexI][IndexJ].color == homeMap[IndexI + 1][IndexJ + 1].color && homeMap[IndexI][IndexJ].color == homeMap[IndexI + 1][IndexJ].color) {
					ChangeBoolPropertyInHexagon(homeMap[IndexI][IndexJ].color);
					DeleteReckonIncenter3HExagonBuild(IndexI, IndexJ, IndexI + 1, IndexJ + 1, IndexI + 1, IndexJ, homeMap[IndexI][IndexJ].color);
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
					DeleteReckonIncenter3HExagonBuild(IndexI, IndexJ, IndexI, IndexJ - 1, IndexI - 1, IndexJ - 1, homeMap[IndexI][IndexJ].color);
					homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI][IndexJ - 1].color = BaseDiscoveringColor;
					homeMap[IndexI - 1][IndexJ - 1].color = BaseDiscoveringColor;
					InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
					return false;
				}
				else if (homeMap[IndexI][IndexJ].color == homeMap[IndexI - 1][IndexJ].color && homeMap[IndexI][IndexJ].color == homeMap[IndexI][IndexJ + 1].color) {
					ChangeBoolPropertyInHexagon(homeMap[IndexI][IndexJ].color);
					DeleteReckonIncenter3HExagonBuild(IndexI, IndexJ, IndexI - 1, IndexJ, IndexI, IndexJ + 1, homeMap[IndexI][IndexJ].color);
					homeMap[IndexI][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI - 1][IndexJ].color = BaseDiscoveringColor;
					homeMap[IndexI][IndexJ + 1].color = BaseDiscoveringColor;
					InvalidateRect(g_hDiscoveringWnd, NULL, TRUE);
					return false;
				}
				else if (homeMap[IndexI][IndexJ].color == homeMap[IndexI + 1][IndexJ].color && homeMap[IndexI][IndexJ].color == homeMap[IndexI + 1][IndexJ - 1].color) {
					ChangeBoolPropertyInHexagon(homeMap[IndexI][IndexJ].color);
					DeleteReckonIncenter3HExagonBuild(IndexI, IndexJ, IndexI + 1, IndexJ, IndexI + 1, IndexJ - 1, homeMap[IndexI][IndexJ].color);
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
	case COLOR_SHOOTERS:        if (shooters.isPlaced) return false; break;
	case COLOR_GUARDIANS:       if (guardians.isPlaced) return false; break;
	case COLOR_CARRIERS:        if (carriers.isPlaced) return false; break;
	case COLOR_EATERS:          if (eaters.isPlaced) return false; break;
	case COLOR_METEORITES:      if (meteorites.isPlaced) return false; break;
	case COLOR_CRYSTALHOLES:    if (crystalHoles.isPlaced) return false; break;
	case COLOR_VIRUSES:         if (viruses.isPlaced) return false; break;
	case COLOR_EVOLUTIONS:      if (evolutions.isPlaced) return false; break;
	case COLOR_ORDINARYCAVES:   if (ordinaryCaves.isPlaced) return false; break;
	case COLOR_WILDANIMALS:     if (wildAnimals.isPlaced) return false; break;
	case COLOR_RURALCONTESTS:   if (ruralContests.isPlaced) return false; break;
	case COLOR_LADYBUGS:        if (ladybugs.isPlaced) return false; break;
	case COLOR_SHELLS:          if (shells.isPlaced) return false; break;
	case COLOR_FABRICRESOURCES: if (fabricResources.isPlaced) return false; break;
	case COLOR_WARCAVES:        if (warCaves.isPlaced) return false; break;
	case HatchingAnimals::HatchingAnimalColor:  if (HatchingAnimals::QuantityOfHatchingAnimalsBuilding >= 4) return false; break;
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
float ReckonVectorSize(POINT A, POINT B) {
	return std::sqrt((std::pow((float)A.x - B.x, 2) + std::pow((float)A.y - B.y, 2)));
}
PathStep FindNearestBuilding(std::list<PathStep>& buildings) {
	float tempDst = 0, curDst = FLT_MAX;
	PathStep nearest_build;
	for (PathStep& build : buildings) {
		tempDst = ReckonVectorSize({373,365},build.pos);
		if (tempDst < curDst) {
			curDst = tempDst;
			nearest_build = build;
		}
	}
	return nearest_build;
}
void RecursiveFindFasterRun(std::list<PathStep>& buildings, PathStep& curBuild) {
	for (PathStep& build : buildings) {
		if (build.isPassed) {
			continue; 
		}
		float curDisttant = ReckonVectorSize(build.pos, curBuild.pos);
		if (TEMP_DISTANT + curDisttant >= GLOBAL_DISTANT) continue;
		TEMP_DISTANT += curDisttant;
		build.isPassed = true;
		tempDist.push_back(build);
		QUANTITY_OF_ELEMENTS_PASSED_CURRENT++;
		RecursiveFindFasterRun(buildings,build);
		if ((QUANTITY_OF_ELEMENTS_PASSED_CURRENT >= QUANTITY_OF_ELEMENTS_PASSED_MAX)) {
			if (GLOBAL_DISTANT > TEMP_DISTANT) {
				GLOBAL_DISTANT = TEMP_DISTANT;
				fastDist = tempDist;
			}
		}
		TEMP_DISTANT -= ReckonVectorSize(build.pos, curBuild.pos);
		QUANTITY_OF_ELEMENTS_PASSED_CURRENT--;
		tempDist.pop_back();
		build.isPassed = false;
	}
}
void SaveHomeMap() {
	std::list<PathStep> buildings;
	if (shooters.incenter.x != 0 && shooters.incenter.y != 0)
		buildings.push_back({shooters.type,shooters.incenter,false});
	if (guardians.incenter.x != 0 && guardians.incenter.y != 0)
		buildings.push_back({ guardians.type,guardians.incenter,false });
	if (carriers.incenter.x != 0 && carriers.incenter.y != 0)
		buildings.push_back({ carriers.type,carriers.incenter,false });
	if (eaters.incenter.x != 0 && eaters.incenter.y != 0)
		buildings.push_back({ eaters.type,eaters.incenter,false });
	if (meteorites.incenter.x != 0 && meteorites.incenter.y != 0)
		buildings.push_back({ meteorites.type,meteorites.incenter,false });
	if (crystalHoles.incenter.x != 0 && crystalHoles.incenter.y != 0)
		buildings.push_back({ crystalHoles.type,crystalHoles.incenter,false });
	if (viruses.incenter.x != 0 && viruses.incenter.y != 0)
		buildings.push_back({ viruses.type,viruses.incenter,false });
	if (evolutions.incenter.x != 0 && evolutions.incenter.y != 0)
		buildings.push_back({ evolutions.type,evolutions.incenter,false });
	if (ordinaryCaves.incenter.x != 0 && ordinaryCaves.incenter.y != 0)
		buildings.push_back({ ordinaryCaves.type,ordinaryCaves.incenter,false });
	if (wildAnimals.incenter.x != 0 && wildAnimals.incenter.y != 0)
		buildings.push_back({ wildAnimals.type,wildAnimals.incenter,false });
	if (ruralContests.incenter.x != 0 && ruralContests.incenter.y != 0)
		buildings.push_back({ ruralContests.type,ruralContests.incenter,false });
	if (ladybugs.incenter.x != 0 && ladybugs.incenter.y != 0)
		buildings.push_back({ ladybugs.type,ladybugs.incenter,false });
	if (shells.incenter.x != 0 && shells.incenter.y != 0)
		buildings.push_back({ shells.type,shells.incenter,false });
	if (fabricResources.incenter.x != 0 && fabricResources.incenter.y != 0)
		buildings.push_back({ fabricResources.type,fabricResources.incenter,false });
	if (warCaves.incenter.x != 0 && warCaves.incenter.y != 0)
		buildings.push_back({ warCaves.type,warCaves.incenter,false });
	float faster_distant = 0; std::list<PathStep> faster_buildings_distant;
	QUANTITY_OF_ELEMENTS_PASSED_MAX = buildings.size();
	PathStep NEAREST_BUILDING_TO_CENTER = FindNearestBuilding(buildings);
	RecursiveFindFasterRun(buildings, NEAREST_BUILDING_TO_CENTER);
	int m = 0;
}