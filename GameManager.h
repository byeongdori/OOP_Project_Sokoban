#pragma once
#include <Windows.h>
#include "MAP.h"

class GameManager
{
private:
public:
	GameManager();
	~GameManager();
	HBITMAP createbitmap(int bitmapindex);
	void draw(HDC hdc, HDC Memdc, HBITMAP draw, int x, int y,
		      int cx, int cy);
	bool checkgameend(MAP map);
};

