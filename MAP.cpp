#include "MAP.h"

MAP::MAP(int arr[][10][10], int mapindex)                           // �� ������, ��ü ��� ���� �ʱ�ȭ
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

void MAP::setinitialize(int arr[][10][10], int mapindex)            // �ʱ� �� ���·� �ǵ����� �Լ�
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

void MAP::move_up()                                                 // �������� �̵� ���� - �� ����Ű
{
	if (currentX - 1 < 0)                                           // ���� ���� ������ ������� �ϴ� ���
		return ;
	if (map[currentX - 1][currentY] == 0)                           // �̵��ϰ��� �ϴ� ������ ������ ���
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX - 1][currentY] = 99;
		currentX--;

	}

	else if (map[currentX - 1][currentY] == 3)                      // �̵��ϰ��� �ϴ� ������ ������ ���
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX - 1][currentY] = 102;
		currentX--;

	}

	else if (map[currentX - 1][currentY] == 2)                      // �̵��ϰ��� �ϴ� ������ ��ź�� ���
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

void MAP::move_down()                                            // �������� �̵� ���� - �Ʒ� ����Ű
{
	if (currentX + 1 > 9)                                        // ���� ���� ������ ������� �ϴ� ���
		return; 
	if (map[currentX + 1][currentY] == 0)						 // �̵��ϰ��� �ϴ� ������ ������ ���
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX + 1][currentY] = 99;
		currentX++;
	}
	else if (map[currentX + 1][currentY] == 3)					 // �̵��ϰ��� �ϴ� ������ ������ ���
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX + 1][currentY] = 102;
		currentX++;
	}

	else if (map[currentX + 1][currentY] == 2)				      // �̵��ϰ��� �ϴ� ������ ��ź�� ���
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

void MAP::move_right()												// �������� �̵� ���� - ���� ����Ű	
{
	if (currentY + 1 < 0)										    // ���� ���� ������ ������� �ϴ� ���
		return;

	if (map[currentX][currentY + 1] == 0)							// �̵��ϰ��� �ϴ� ������ ������ ���
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX][currentY + 1] = 99;
		currentY++;
	}

	else if (map[currentX][currentY + 1] == 3)						 // �̵��ϰ��� �ϴ� ������ ������ ���
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX][currentY + 1] = 102;
		currentY++;
	}

	else if (map[currentX][currentY + 1] == 2)							// �̵��ϰ��� �ϴ� ������ ��ź�� ���
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

void MAP::move_left()										// �������� �̵� ���� - ���� ����Ű	
{
	if (currentY - 1 < 0)									// ���� ���� ������ ������� �ϴ� ���
		return;
	if (map[currentX][currentY - 1] == 0)                   // �̵��ϰ��� �ϴ� ������ ������ ���
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX][currentY - 1] = 99;
		currentY--;
	}
	else if (map[currentX][currentY - 1] == 3)				// �̵��ϰ��� �ϴ� ������ ������ ���
	{
		if (map[currentX][currentY] == 99)
			map[currentX][currentY] = 0;
		else if (map[currentX][currentY] == 102)
			map[currentX][currentY] = 3;

		map[currentX][currentY - 1] = 102;
		currentY--;
	}
	else if (map[currentX][currentY - 1] == 2)				// �̵��ϰ��� �ϴ� ������ ��ź�� ���
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

int MAP::getstatus(int x, int y)                         // ���� ��ġ�� ���� ��ȯ - ex) ������,��������..etc
{
	return map[x][y];
}

int MAP::checkhole(int x, int y)                         // ���� ��ġ�� ���ۿ� ���� ���Դ��� �ȵ���ִ��� ��ȯ 
{
	return savemap[x][y];
}