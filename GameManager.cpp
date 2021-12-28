#include "GameManager.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

HBITMAP GameManager::createbitmap(int bitmapindex)                                 // ��Ʈ�� ����
{
	return LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(bitmapindex));
}

void GameManager::draw(HDC hdc, HDC Memdc, HBITMAP draw, int x, int y,              
	int cx, int cy)                                                                // ��Ʈ�� ȭ�鿡 �׸���
{
	HBITMAP tempBitmap;
	tempBitmap = (HBITMAP)SelectObject(Memdc, draw);
	BitBlt(hdc, x, y, cx, cy, Memdc, 0, 0, SRCCOPY);
	SelectObject(Memdc, tempBitmap);
}

bool GameManager::checkgameend(MAP map)                                            // �� Ŭ���� �ߴ��� �Ǵ��ϴ� �Լ�
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