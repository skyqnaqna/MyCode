/*
백준 1080번 행렬
https://www.acmicpc.net/problem/1080
20/03/06
*/

#include <iostream>

using namespace std;

void reverse(int x, int y);

int aa[50][50];
int bb[50][50];
bool cc[50][50];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);

	int k;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%1d", &aa[i][j]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%1d", &bb[i][j]);
			if (aa[i][j] == bb[i][j])
				cc[i][j] = false;
			else
				cc[i][j] = true;
		}
	}

	int count(0);

	if (n < 3 || m < 3)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (aa[i][j] != bb[i][j])
				{
					printf("%d\n", -1);
					return 0;
				}
			}
		}
		printf("%d\n", 0);
		return 0;
	}
	else
	{
		for (int i = 0; i <= n - 3; ++i)
		{
			for (int j = 0; j <= m - 3; ++j)
			{
				if (cc[i][j])
				{
					reverse(i, j);
					++count;
				}
				if (j == m - 3)
				{
					if (cc[i][j + 1] || cc[i][j + 2])
					{
						printf("%d\n", -1);
						return 0;
					}
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (cc[i][j])
				{
					printf("%d\n", -1);
					return 0;
				}
			}
		}
		printf("%d\n", count);

	}

	return 0;
}

void reverse(int x, int y)
{
	for (int i = x; i < x + 3; ++i)
	{
		for (int j = y; j < y + 3; ++j)
		{
			aa[i][j] = 1 - aa[i][j];
			if (aa[i][j] == bb[i][j])
				cc[i][j] = false;
			else
				cc[i][j] = true;
		}
	}
}
