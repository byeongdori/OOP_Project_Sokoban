#pragma once
class MAP
{
private:
	int currentX;                                         // 플레이어의 현재 배열상의 X 위치
	int currentY;                                         // 플레이어의 현재 배열상의 Y 위치
	int map[10][10];                                      // 1은 벽, 0은 공백, 2는 폭탄, 99는 현재플레이어, 3은 구멍(목적지), 102인 경우 구멍위에 플레이어가 서있는 경우
	int savemap[10][10];                                  // 0인 경우 구멍, 10인 경우 구멍에 공이 들어가 있는 경우, 그 외 1

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

