#pragma once

#include <Windows.h>
#include <Windowsx.h>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <atomic>

#define WM_DISCOVER_PROGRESS (WM_USER + 1)
#define WM_TIME_PROGRESS (WM_USER + 2)
#define OnButtonStartClick		1
#define OnButtonDiscoverClick		2

int SecondsWordProgram = 0;
int MinutesWordProgram = 0;
int HoursWordProgram = 0;

std::atomic<bool> isActive{ false };
std::atomic<bool> isDiscovering{ false };
std::atomic<bool> isProgramWork{ true };
std::atomic<bool> isActivateProgram{ false };

HBRUSH THEMEWINDOWCOLOR = CreateSolidBrush(RGB(255, 255, 255));

HWND g_hMainWnd = nullptr;
HWND StatusTextStart;
HWND ActiveControlTextStatus;
HWND StatusTextTime;
HWND ActiveControlTextStatusTime;
HWND DiscoverStatusText;

HANDLE readNewWindow;
HANDLE readKey;
HANDLE readTime;

COLORREF ActiveTextColor;
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
LRESULT CALLBACK SoftwareDiscoveringProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void SetActiveTextColor(COLORREF color, HWND ActiveControlText);
void MainWndAddMenus(HWND hWnd);
void MainWndWidgets(HWND hWnd);
void ExitSoftware(void);
void ExitDiscoveringSoftware(void);
void DiscoveringWndWidgets(HWND hWnd);

DWORD WINAPI ReadKeysInput(LPVOID lpParameter);
DWORD WINAPI ThreadDiscover(LPVOID lpParameter);
DWORD WINAPI ThreadTimeProgres(LPVOID lpParameter);