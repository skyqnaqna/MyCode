/*
백준 14889번 스타트와 링크
https://www.acmicpc.net/problem/14889
20/10/09
*/

#include <iostream>
#include <algorithm>

using namespace std;

int point[21][21];
bool check[21];
int minPoint = 987654321;
int n;

void Find(int a, bool b, int count)
{
	if (a > n) return;

	int cnt = count;
	check[a] = b;
	if (check[a]) ++cnt;

	if (cnt == n / 2)
	{
		int x(0), y(0);
		for (int i = 1; i <= n; ++i)
		{
			if (check[i])
			{
				for (int j = 1; j <= n; ++j)
				{
					if (check[j]) x += point[i][j];
				}
			}
			else
			{
				for (int j = 1; j <= n; ++j)
				{
					if (!check[j]) y += point[i][j];
				}
			}
		}
		if (abs(x - y) < minPoint) minPoint = abs(x - y);
		
		return;
	}
	else
	{
		Find(a + 1, true, cnt);
		Find(a + 1, false, cnt);
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		check[i] = false;

		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &point[i][j]);
		}
	}

	check[1] = true;
	Find(2, true, 1);
	Find(2, false, 1);

	printf("%d\n", minPoint);

	return 0;
}
