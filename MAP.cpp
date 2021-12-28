#include "MAP.h"

MAP::MAP(int arr[][10][10], int mapindex)                           // 맵 생성자, 객체 멤버 변수 초기화
{
	for (int i = 0; i < 10; i++)
	{
		for (int y = 0; y < 10; y++)
		{
			map[i][y] = arr[mapindex][i][y];

			if (arr[mapindex][i][y] == 99)
			{
				currentX = i;
				currentY = y;
			}

			if (arr[mapindex][i][y] == 3)
				savemap[i][y] = 0;
			else
				savemap[i][y] = 1;

		}
	}
}

MAP::~MAP()
{

}

void MAP::setinitialize(int arr[][10][10], int mapindex)            // 초기 맵 상태로 되돌리는 함수
{
	for (int i = 0; i < 10; i++)
	{
		for (int y = 0; y < 10; y++)
		{
			map[i][y] = arr[mapindex][i][y];

			if (arr[mapindex][i][y] == 99)
			{
				currentX = i;
				currentY = y;
			}

			if (arr[mapindex][i][y] == 3)
				savemap[i][y] = 0;
			else
				savemap[i][y] = 1;

		}
	}
}

void MAP::move_up()                                                 // 실질적인 이동 구현 - 위 방향키
{
	if (currentX - 1 < 0)                                           // 게임 구역 밖으로 벗어나려고 하는 경우
		return ;
	if (map[currentX - 1][currentY] == 0)                           // 이동하고자 하는 방향이 공백인 경우
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX - 1][currentY] = 99;
		currentX--;

	}

	else if (map[currentX - 1][currentY] == 3)                      // 이동하고자 하는 방향이 구멍인 경우
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX - 1][currentY] = 102;
		currentX--;

	}

	else if (map[currentX - 1][currentY] == 2)                      // 이동하고자 하는 방향이 폭탄인 경우
	{
		if ((currentX - 1) == 0 || map[currentX - 2][currentY] == 1 || map[currentX - 2][currentY] == 2 || savemap[currentX - 2][currentY] == 10)
			return ;
		else
		{
			if (map[currentX][currentY] == 99)
				map[currentX][currentY] = 0;
			else if (map[currentX][currentY] == 102)
				map[currentX][currentY] = 3;

			if (savemap[currentX - 1][currentY] == 10)                   
			{
				map[currentX - 1][currentY] = 102;
				savemap[currentX - 1][currentY] = 0;
			}
			else
				map[currentX - 1][currentY] = 99;

			if (savemap[currentX - 2][currentY] == 0 && map[currentX - 2][currentY] == 3)
				savemap[currentX - 2][currentY] = 10;

			map[currentX - 2][currentY] = 2;
			currentX--;
		}
	}
}

void MAP::move_down()                                            // 실질적인 이동 구현 - 아래 방향키
{
	if (currentX + 1 > 9)                                        // 게임 구역 밖으로 벗어나려고 하는 경우
		return; 
	if (map[currentX + 1][currentY] == 0)						 // 이동하고자 하는 방향이 공백인 경우
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX + 1][currentY] = 99;
		currentX++;
	}
	else if (map[currentX + 1][currentY] == 3)					 // 이동하고자 하는 방향이 구멍인 경우
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX + 1][currentY] = 102;
		currentX++;
	}

	else if (map[currentX + 1][currentY] == 2)				      // 이동하고자 하는 방향이 폭탄인 경우
	{
		if ((currentX + 1) == 0 || map[currentX + 2][currentY] == 1 || map[currentX + 2][currentY] == 2 || savemap[currentX + 2][currentY] == 10)
			return;
		else
		{
			if (map[currentX][currentY] == 99)
				map[currentX][currentY] = 0;
			else if (map[currentX][currentY] == 102)
				map[currentX][currentY] = 3;

			if (savemap[currentX + 1][currentY] == 10)                   
			{
				map[currentX + 1][currentY] = 102;
				savemap[currentX + 1][currentY] = 0;
			}
			else
				map[currentX + 1][currentY] = 99;

			if (savemap[currentX + 2][currentY] == 0 && map[currentX + 2][currentY] == 3)
				savemap[currentX + 2][currentY] = 10;

			map[currentX + 2][currentY] = 2;
			currentX++;
		}
	}
}

void MAP::move_right()												// 실질적인 이동 구현 - 우측 방향키	
{
	if (currentY + 1 < 0)										    // 게임 구역 밖으로 벗어나려고 하는 경우
		return;

	if (map[currentX][currentY + 1] == 0)							// 이동하고자 하는 방향이 공백인 경우
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX][currentY + 1] = 99;
		currentY++;
	}

	else if (map[currentX][currentY + 1] == 3)						 // 이동하고자 하는 방향이 구멍인 경우
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX][currentY + 1] = 102;
		currentY++;
	}

	else if (map[currentX][currentY + 1] == 2)							// 이동하고자 하는 방향이 폭탄인 경우
	{
		if ((currentY + 1) == 0 || map[currentX][currentY + 2] == 1 || map[currentX][currentY + 2] == 2 || savemap[currentX][currentY + 2] == 10)
			return;
		else
		{
			if (map[currentX][currentY] == 99)
				map[currentX][currentY] = 0;
			else if (map[currentX][currentY] == 102)
				map[currentX][currentY] = 3;

			if (savemap[currentX][currentY + 1] == 10)                   
			{
				map[currentX][currentY + 1] = 102;
				savemap[currentX][currentY + 1] = 0;
			}
			else
				map[currentX][currentY + 1] = 99;

			if (savemap[currentX][currentY + 2] == 0 && map[currentX][currentY + 2] == 3)
				savemap[currentX][currentY + 2] = 10;

			map[currentX][currentY + 2] = 2;
			currentY++;
		}
	}
}

void MAP::move_left()										// 실질적인 이동 구현 - 좌측 방향키	
{
	if (currentY - 1 < 0)									// 게임 구역 밖으로 벗어나려고 하는 경우
		return;
	if (map[currentX][currentY - 1] == 0)                   // 이동하고자 하는 방향이 공백인 경우
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX][currentY - 1] = 99;
		currentY--;
	}
	else if (map[currentX][currentY - 1] == 3)				// 이동하고자 하는 방향이 구멍인 경우
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX][currentY - 1] = 102;
		currentY--;
	}
	else if (map[currentX][currentY - 1] == 2)				// 이동하고자 하는 방향이 폭탄인 경우
	{
		if ((currentY - 1) == 0 || map[currentX][currentY - 2] == 1 || map[currentX][currentY - 2] == 2 || savemap[currentX][currentY - 2] == 10)
			return;
		else
		{
			if (map[currentX][currentY] == 99)
				map[currentX][currentY] = 0;
			else if (map[currentX][currentY] == 102)
				map[currentX][currentY] = 3;

			if (savemap[currentX][currentY - 1] == 10)                   
			{
				map[currentX][currentY - 1] = 102;
				savemap[currentX][currentY - 1] = 0;
			}
			else
				map[currentX][currentY - 1] = 99;

			if (savemap[currentX][currentY - 2] == 0 && map[currentX][currentY - 2] == 3)
				savemap[currentX][currentY - 2] = 10;

			map[currentX][currentY - 2] = 2;
			currentY--;
		}
	}
}

int MAP::getstatus(int x, int y)                         // 현재 위치의 상태 반환 - ex) 벽인지,구멍인지..etc
{
	return map[x][y];
}

int MAP::checkhole(int x, int y)                         // 현재 위치의 구멍에 공이 들어왔는지 안들어있는지 반환 
{
	return savemap[x][y];
}