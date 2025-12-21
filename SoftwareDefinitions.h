#pragma once
#define _USE_MATH_DEFINES
#include <Windows.h>
#include <Windowsx.h>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <atomic>
#include <cmath>
#include <list>
#include "SoftwareNameSpaces.h"

#define WM_DISCOVER_PROGRESS (WM_USER + 1)
#define WM_TIME_PROGRESS (WM_USER + 2)
#define OnButtonStartClick		1
#define OnButtonDiscoverClick		2

#define OnButtonCurrentColor		3
#define OnButtonBaseColorClick		4
#define OnButtonShootersClick		5
#define OnButtonGuardiansClick		6
#define OnButtonCarriersClick		7
#define OnButtonEateClick			8
#define OnButtonMeteoritClick		9
#define OnButtonCrystalHoleClick	10
#define OnButtonVirusesClick		11
#define OnButtonEvolutionClick		12
#define OnButtonCavesClick			13
#define OnButtonWildAnimalClick		14
#define OnButtonRuralContestClick	15
#define OnButtonLadybugClick		16
#define OnButtonShellClick			17
#define OnButtonFabricResources		18
#define OnButtonWarCaveClick		19
#define OnButtonHatchingAnimalClick	20
#define OnButtonAntSlayerClick		21
#define OnButtonAnimalCormClick		22
#define OnButtonDiscoverSaveClick	23
#define OnButtonDiscoverCancelClick	24

#define COLOR_SHOOTERS RGB(0, 0, 255)
#define COLOR_GUARDIANS RGB(255, 0, 0)
#define COLOR_CARRIERS RGB(0, 255, 0)
#define COLOR_EATERS RGB(0, 255, 255)
#define COLOR_METEORITES RGB(127, 0, 255)
#define COLOR_CRYSTALHOLES RGB(178, 102, 255)
#define COLOR_VIRUSES RGB(18, 198, 243)
#define COLOR_EVOLUTIONS RGB(255, 102, 102)
#define COLOR_ORDINARYCAVES RGB(102, 178, 255)
#define COLOR_WILDANIMALS RGB(255, 255, 153)
#define COLOR_RURALCONTESTS RGB(255, 51, 153)
#define COLOR_LADYBUGS RGB(204, 0, 0)
#define COLOR_SHELLS RGB(255, 255, 204)
#define COLOR_FABRICRESOURCES RGB(153, 255, 153)
#define COLOR_WARCAVES RGB(153, 0, 0)


int SecondsWordProgram = 0;
int MinutesWordProgram = 0;
int HoursWordProgram = 0;

std::atomic<bool> isActive{ false };
std::atomic<bool> isDiscovering{ false };
std::atomic<bool> isProgramWork{ true };
std::atomic<bool> isActivateProgram{ false };
std::atomic<bool> isNearestHexagonDetermined{ false };

HBRUSH THEMEWINDOWCOLOR = CreateSolidBrush(RGB(255, 255, 255));

HWND g_hMainWnd = nullptr;
HWND g_hDiscoveringWnd = nullptr;
HWND StatusTextStart;
HWND ActiveControlTextStatus;
HWND StatusTextTime;
HWND ActiveControlTextStatusTime;
HWND DiscoverStatusText;
HWND DiscoverSaveButton;
HWND DiscoverCancelButton;

HWND ButtonDiscoveryCurrentColor;
HWND ButtonDiscoveryBaseColor;

HANDLE readNewWindow;
HANDLE readKey;
HANDLE readTime;

COLORREF ActiveTextColor;
COLORREF CurrentDiscoveringColor;

const COLORREF BaseDiscoveringColor = RGB(192,192,192);

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
LRESULT CALLBACK SoftwareDiscoveringProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void SetActiveTextColor(COLORREF color, HWND ActiveControlText);
void MainWndAddMenus(HWND hWnd);
void MainWndWidgets(HWND hWnd);
void ExitSoftware(void);
void ExitDiscoveringSoftware(void);
void DiscoveringWndWidgets(HWND hWnd);
void CreateDiscoveringMap(HWND hWnd);
void SetNeededColor(int x, int y);
bool CheckIfGather3Hexagon(int IndexI, int IndexJ);
bool CheckIfAvailableFor1Hexagon(int IndexI, int IndexJ);
void ChangeBoolPropertyInHexagon(COLORREF HexagonColor);
bool Set1HexagonConstruction(int targetI, int targetJ);
bool Set3HexagonConstruction(int targetI, int targetJ);
void DeleteReckonIncenter3HExagonBuild(int targetI1, int targetJ1, int targetI2, int targetJ2, int targetI3, int targetJ3, COLORREF col);
void ReckonIncenter3HExagonBuild(int targetI1, int targetJ1, int targetI2, int targetJ2, int targetI3, int targetJ3);
void CreateDiscoveringMapBuildings();

void DeleteReckonIncenter1HExagonBuild(int targetI, int targetJ);
void SaveHomeMap();

DWORD WINAPI ReadKeysInput(LPVOID lpParameter);
DWORD WINAPI ThreadDiscover(LPVOID lpParameter);
DWORD WINAPI ThreadTimeProgres(LPVOID lpParameter);

struct HEXAGON {
	int centerX;
	int centerY;
	int radius;
	COLORREF color;
};

HEXAGON homeMap[35][35];

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