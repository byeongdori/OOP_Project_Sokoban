#include "GameManager.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

HBITMAP GameManager::createbitmap(int bitmapindex)                                 // 비트맵 생성
{
	return LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(bitmapindex));
}

void GameManager::draw(HDC hdc, HDC Memdc, HBITMAP draw, int x, int y,              
	int cx, int cy)                                                                // 비트맵 화면에 그리기
{
	HBITMAP tempBitmap;
	tempBitmap = (HBITMAP)SelectObject(Memdc, draw);
	BitBlt(hdc, x, y, cx, cy, Memdc, 0, 0, SRCCOPY);
	SelectObject(Memdc, tempBitmap);
}

bool GameManager::checkgameend(MAP map)                                            // 맵 클리어 했는지 판단하는 함수
{
		for (int i = 0; i < 10; i++)
		{
			for (int y = 0; y < 10; y++)
			{
				if ((map.checkhole(i, y)) == 0)
					return false;
			}
		}
		return true;
}