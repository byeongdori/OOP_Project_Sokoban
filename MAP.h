#pragma once
class MAP
{
private:
	int currentX;                                         // �÷��̾��� ���� �迭���� X ��ġ
	int currentY;                                         // �÷��̾��� ���� �迭���� Y ��ġ
	int map[10][10];                                      // 1�� ��, 0�� ����, 2�� ��ź, 99�� �����÷��̾�, 3�� ����(������), 102�� ��� �������� �÷��̾ ���ִ� ���
	int savemap[10][10];                                  // 0�� ��� ����, 10�� ��� ���ۿ� ���� �� �ִ� ���, �� �� 1

public:
	MAP(int arr[][10][10], int mapindex);
	~MAP();
	void setinitialize(int arr[][10][10], int mapindex);
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	int getstatus(int x, int y);
	int checkhole(int x, int y);
};

