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

int SecondsWordProgram = 0;
int MinutesWordProgram = 0;
int HoursWordProgram = 0;

int QuantityOfAntSlayerBuilding = 0;
int QuantityOfAnimalCormBuilding = 0;
int QuantityOfHatchingAnimalsBuilding = 0;

std::atomic<bool> GuardianHexagons{ false };
std::atomic<bool> ShooterHexagons{ false };
std::atomic<bool> CarrierHexagons{ false };
std::atomic<bool> EateHexagons{ false };
std::atomic<bool> MeteoritHexagons{ false };
std::atomic<bool> CrystalHoleHexagons{ false };
std::atomic<bool> VirusesHexagons{ false };
std::atomic<bool> EvolutionsHexagons{ false };
std::atomic<bool> OrdinaryCaveHexagons{ false };
std::atomic<bool> WildAnimalHexagons{ false };
std::atomic<bool> RuralContestHexagons{ false };
std::atomic<bool> LadybugHexagons{ false };
std::atomic<bool> ShellHexagons{ false };
std::atomic<bool> FabricResourcesHexagons{ false };
std::atomic<bool> WarCaveHexagons{ false };

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

HWND ButtonDiscoveryCurrentColor;
HWND ButtonDiscoveryBaseColor;
HWND ButtonDiscoveryShootersColor;
HWND ButtonDiscoveryGuardiansColor;
HWND ButtonDiscoveryCarriersColor;
HWND ButtonDiscoveryEateColor;
HWND ButtonDiscoveryMeteoritColor;
HWND ButtonDiscoveryCrystalHoleColor;
HWND ButtonDiscoveryVirusesColor;
HWND ButtonDiscoveryEvolutionsColor;
HWND ButtonDiscoveryOrdinaryCaveColor;
HWND ButtonDiscoveryWildAnimalColor;
HWND ButtonDiscoveryRuralContestColor;
HWND ButtonDiscoveryLadybugColor;
HWND ButtonDiscoveryShellColor;
HWND ButtonDiscoveryFabricResourcesColor;
HWND ButtonDiscoveryWarCaveColor;
HWND ButtonDiscoveryHatchingAnimalColor;
HWND ButtonDiscoveryAntAlayerColor;
HWND ButtonDIscoveryAnimalCormColor;

HANDLE readNewWindow;
HANDLE readKey;
HANDLE readTime;

COLORREF ActiveTextColor;
COLORREF CurrentDiscoveringColor;

const COLORREF BaseDiscoveringColor = RGB(192,192,192);
const COLORREF ShootersColor = RGB(0,0,255);
const COLORREF GuardianColor = RGB(255,0,0);
const COLORREF CarriersColor = RGB(0,255,0);
const COLORREF EateColor = RGB(0,255,255);
const COLORREF MeteoritColor = RGB(127, 0, 255);
const COLORREF CrystalHoleColor = RGB(178, 102, 255);
const COLORREF VirusesColor = RGB(18, 198, 243);
const COLORREF EvolutionsColor = RGB(255, 102, 102);
const COLORREF OrdinaryCaveColor = RGB(102, 178, 255);
const COLORREF WildAnimalBaseColor = RGB(255, 255, 153);
const COLORREF RuralContestsColor = RGB(255, 51, 153);
const COLORREF LadybugColor = RGB(204, 0, 0);
const COLORREF ShellColor = RGB(255, 255, 204);
const COLORREF FabricResourcesColor = RGB(153, 255, 153);
const COLORREF WarCaveColor = RGB(153, 0, 0);
const COLORREF HatchingAnimalColor = RGB(255,128,0);
const COLORREF AntSlayerColor = RGB(0, 102, 51);
const COLORREF AnimalCormColor = RGB(102, 102, 0);

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