
/************************
Originally Written By
김병주, 김태훈, 김찬현, 박준형, 최종윤 in
Chung-ang Univ. 
Comp Sci.
(2020 - 12 - 08)
************************/

#include <Windows.h>
#include "resource.h"
#include "MAP.h"
#include "GameManager.h"
#include "MapResource.h"

#define BOX 48                                                      // 가로 세로 비트맵 한 칸의 크기
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("main");


int menumode = 0;                                                   // 메뉴(장면) 전환을 위해 필요한 변수 
int mapindex = 0;                                                   // 맵 전환을 위한 변수
MAP usemap(map, mapindex);                                          // MAP 객체 생성
GameManager gamemanager;                                            // GameManager 객체 생성

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	// 윈도우 클래스 기본 정의
	WndClass.cbClsExtra = 0;   // 여분 메모리 정의
	WndClass.cbWndExtra = 0;   // 여분 메모리 정의
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   // 배경 색상 지정
	WndClass.hCursor = LoadCursor(NULL, IDC_CROSS);                 // 커서 모양 지정
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);               // 아이콘 모양 지정
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;                                 // 윈도우에서 발생하는 메세지 처리 할 곳
	WndClass.lpszClassName = lpszClass;                             // 윈도우 클래스 이름
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;                       // 윈도우 스타일 옵션

	// 윈도우 클래스 등록
	RegisterClass(&WndClass);

	// 윈도우 생성
	hWnd = CreateWindow(lpszClass, TEXT("Sokoban Game"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		496, 520, NULL, NULL, hInstance, NULL);

	// 화면에 표시
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return (int)message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	HDC Memdc;
	PAINTSTRUCT paint;
	static HBITMAP hWall;         // 벽 객체
	static HBITMAP hblank;        // 빈칸
	static HBITMAP hbomb;         // 폭탄
	static HBITMAP player;        // 플레이어
	static HBITMAP hole;          // 구멍(목적지)
	static HBITMAP mainmenu;      // 메인 화면
	static HBITMAP endmenu;       // 엔딩 화면

	switch (message)
	{

	case WM_CREATE:                                              // 비트맵 객체 생성
		hWall = gamemanager.createbitmap(IDB_WALL);
		hblank = gamemanager.createbitmap(IDB_BLANK);
		hbomb = gamemanager.createbitmap(IDB_BOMB);
		player = gamemanager.createbitmap(IDB_PLAYER);
		hole = gamemanager.createbitmap(IDB_HOLE);
		mainmenu = gamemanager.createbitmap(IDB_MAIN);
		endmenu = gamemanager.createbitmap(IDB_END);
		return 0;

	case WM_KEYDOWN:                                             // 키 입력시 동작 수행 

		if (menumode == 4)
			PostQuitMessage(0);

		switch(wParam)
		{
		case VK_UP:                                              // 위 방향키
			if(menumode != 0)
				usemap.move_up();
			break;
		case VK_DOWN:                                            // 아래 방향키
			if (menumode != 0)
				usemap.move_down();
			break;
		case VK_RIGHT:                                           // 우측 방향키
			if (menumode != 0)
				usemap.move_right();
			break;
		case VK_LEFT:                                            // 좌측방향키
			if (menumode != 0)
				usemap.move_left();
			break;
		case VK_SPACE:                                           // SPACE 
			if (menumode == 0)
				menumode++;
			break;
		case VK_ESCAPE:                                          // ESC
			menumode = 0;
			mapindex = 0;
			usemap.setinitialize(map, mapindex);
			break;
		case 'R':                                                // R --> 맵 재시작
			usemap.setinitialize(map, mapindex);
			break;
		case 'P':                                                // P --> 해당 맵 뛰어넘기
			menumode++;
			mapindex++;
			usemap.setinitialize(map, mapindex);
			break;
		}

		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		return 0;
		 
	case WM_PAINT:                                                         // 화면에 실질적으로 그림 띄우는 단계
		hdc = BeginPaint(hWnd, &paint);
		Memdc = CreateCompatibleDC(hdc);

		if(menumode == 0)
			gamemanager.draw(hdc, Memdc, mainmenu, 0, 0, 500, 520);
		else if (!gamemanager.checkgameend(usemap) && menumode != 4)
		{
			for (int i = 0; i < 10; i++)
				for (int y = 0; y < 10; y++)
				{
					switch (usemap.getstatus(i,y))                                              // 배열의 저장된 값에 따라 화면에 비트맵 그림
					{
					case 102:
					case 99:
						gamemanager.draw(hdc, Memdc, player, y * BOX, i * BOX, BOX, BOX);
						break;
					case 3:
						gamemanager.draw(hdc, Memdc, hole, y * BOX, i * BOX, BOX, BOX);
						break;
					case 77:
					case 2:
						gamemanager.draw(hdc, Memdc, hbomb, y * BOX, i * BOX, BOX, BOX);
						break;
					case 1:
						gamemanager.draw(hdc, Memdc, hWall, y * BOX, i * BOX, BOX, BOX);
						break;
					case 0:
						gamemanager.draw(hdc, Memdc, hblank, y * BOX, i * BOX, BOX, BOX);
						break;
					default:
						break;
					}
				}
		}
		else if (menumode == 4)
			gamemanager.draw(hdc, Memdc, endmenu, 0, 0, 500, 520);
		else
		{
			menumode++;
			mapindex++;
			usemap.setinitialize(map, mapindex);
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
		}
		DeleteDC(Memdc);
		EndPaint(hWnd, &paint);
		return 0;

	case WM_DESTROY:                                                                      // 비트맵 객체 파괴
		DeleteObject(hWall);
		DeleteObject(hblank);
		DeleteObject(hbomb);
		DeleteObject(player);
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, message, wParam, lParam));                                // Winproc 함수 반복
}