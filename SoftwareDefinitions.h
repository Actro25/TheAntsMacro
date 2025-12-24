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
#include <utility>

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

enum class BuildingType {
    None,
    Shooters,
    Guardians,
    Carriers,
    Eaters,
    Meteorites,
    CrystalHoles,
    Viruses,
    Evolutions,
    OrdinaryCaves,
    WildAnimals,
    RuralContests,
    Ladybugs,
    Shells,
    FabricResources,
    WarCaves,
    HatchingAnimals,
    AntSlayers,
    AnimalCorms
};

struct BuildingStruct
{
    std::string name;
    POINT incenter;
    bool isPlaced = false;
    COLORREF Color;
    BuildingType type;
    HWND ButtonColor = NULL;

    void FunctionCreate(std::string name, POINT incenter,
        bool isPlaced, HWND ButtonColor) {
        this->name = name;
        this->incenter = incenter;
        this->isPlaced = isPlaced;
        this->ButtonColor = ButtonColor;
    }

};
struct PathStep {
    BuildingType type;
    POINT pos;
    bool isPassed = false;
};


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
float ReckonVectorSize(POINT A, POINT B);
void RecursiveFindFasterRun(std::list<PathStep>& buildings, PathStep& curBuild);
PathStep FindNearestBuilding(std::list<PathStep>& buildings);

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

namespace HatchingAnimals {
    inline std::list<POINT> incenter;
    inline const COLORREF HatchingAnimalColor = RGB(255, 128, 0);
    inline HWND ButtonDiscoveryHatchingAnimalColor;
    inline BuildingType type = BuildingType::HatchingAnimals;
    inline int QuantityOfHatchingAnimalsBuilding = 0;
}
namespace AntSlayers {
    inline std::list<POINT> incenter;
    inline const COLORREF AntSlayerColor = RGB(0, 102, 51);
    inline HWND ButtonDiscoveryAntSlayerColor;
    inline BuildingType type = BuildingType::AntSlayers;;
    inline int QuantityOfAntSlayerBuilding = 0;
}
namespace AnimalCorms {
    inline std::list<POINT> incenter;
    inline const COLORREF AnimalCormColor = RGB(102, 102, 0);
    inline HWND ButtonDiscoveryAnimalCormColor;
    inline BuildingType type = BuildingType::AnimalCorms;
    inline int QuantityOfAnimalCormBuilding = 0;
}

int QUANTITY_OF_ELEMENTS_PASSED_MAX = 0;
int QUANTITY_OF_ELEMENTS_PASSED_CURRENT = 0;
float GLOBAL_DISTANT = FLT_MAX;
float TEMP_DISTANT = 0;
std::list<PathStep> fastDist;
std::list<PathStep> tempDist;