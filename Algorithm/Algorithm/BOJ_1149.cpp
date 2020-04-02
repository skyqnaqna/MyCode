/*
백준 1149번 RGB거리
20/04/03
*/
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][3] = { 0 };
int house[1001][3] = { 0 };

int main(void)
{	
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
			scanf("%d", &house[i][j]);

	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];

	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = house[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	int result = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);

	printf("%d\n", result);

	return 0;
}
