/*
백준 1937번 욕심쟁이 판다
20/03/27
*/
#include <iostream>
#include <algorithm>

using namespace std;

int map[501][501] = { 0 };
int info[501][501] = { 0 };

int n;

int getResult(int, int);

int main(void)
{	
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &map[i][j]);

	int max(0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			info[i][j] = getResult(i, j);
			if (info[i][j] > max) max = info[i][j];
		}
	}

	printf("%d\n", max);
		
	return 0;
}

int getResult(int row, int col)
{
	int up(0), down(0), left(0), right(0);
	int now = map[row][col];

	if (row < 0 || row >= n || col < 0 || col >= n) return 0;

	if (info[row][col] > 0) return info[row][col];
	else
	{
		// up
		if (now < map[row - 1][col] && row - 1 >= 0)
		{
			if (info[row - 1][col] > 0)
				up = info[row - 1][col] + 1;
			else
			{
				up = getResult(row - 1, col) + 1;
				info[row - 1][col] = up - 1;
			}
		}
		// down
		if (now < map[row + 1][col] && row + 1 < n)
		{
			if (info[row + 1][col] > 0)
				down = info[row + 1][col] + 1;
			else
			{
				down = getResult(row + 1, col) + 1;
				info[row + 1][col] = down - 1;
			}
		}
		// left
		if (now < map[row][col - 1] && col - 1 >= 0)
		{
			if (info[row][col - 1] > 0)
				left = info[row][col - 1] + 1;
			else
			{
				left = getResult(row, col - 1) + 1;
				info[row][col - 1] = left - 1;
			}		
		}
		// right
		if (now < map[row][col + 1] && col + 1 < n)
		{
			if (info[row][col + 1] > 0)
				right = info[row][col + 1] + 1;
			else
			{
				right = getResult(row, col + 1) + 1;
				info[row][col + 1] = right - 1;
			}
		}
		if (up == 0 && down == 0 && left == 0 && right == 0) return 1;

		return max(max(up, down), max(left, right));
	}
	
}
