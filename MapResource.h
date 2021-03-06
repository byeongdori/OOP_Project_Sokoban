#pragma once

// 1은 벽, 0은 공백, 2는 폭탄, 99는 현재플레이어, 3은 구멍(목적지)

int map[3][10][10] =                                                    // 3차원 배열 - 첫번째는 맵의 개수, 두번째&세번째 인자는 맵의 초기 상태 나타냄
{
	{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 3, 1, 1, 1, 1, 1 },
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
	{1, 1, 1, 1, 2, 0, 2, 3, 1, 1 },
	{1, 1, 3, 0, 2, 99, 1, 1, 1, 1 },
	{1, 1, 1, 1, 1, 2, 1, 1, 1, 1 },
	{1, 1, 1, 1, 1, 3, 1, 1, 1, 1 },
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	},
	{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 99, 0, 0, 1, 1, 1, 1, 1},
	{1, 1, 0, 2, 2, 1, 1, 1, 1, 1},
	{1, 1, 0, 2, 0, 1, 1, 1, 3, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 3, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 3, 1},
	{1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	},
	{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 0, 0, 0, 1, 99, 0, 1},
	{1, 1, 1, 2, 0, 2, 0, 2, 0, 1},
	{1, 1, 1, 0, 2, 1, 1, 0, 0, 1},
	{1, 1, 1, 0, 2, 0, 1, 0, 0, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 3, 3, 3, 3, 3, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	}
};
