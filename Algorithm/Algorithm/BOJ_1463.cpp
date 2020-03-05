/*
백준 1464 1로 만들기
https://www.acmicpc.net/problem/1463
*/

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000000] = { 0 };

int main()
{
	int x;
	scanf("%d", &x);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	// 10의 경우 1을 빼고 하는게 더 최소이므로 뺀것과 나눈것 중 최소를 구한다
	for (int i = 4; i <= x; ++i)
	{
		if (i % 3 == 0)
			dp[i] = min(1 + dp[i / 3], 1 + dp[i - 1]);
		else if (i % 2 == 0)
			dp[i] = min(1 + dp[i / 2], 1 + dp[i - 1]);
		else
			dp[i] = 1 + dp[i - 1];
	}

	printf("%d\n", dp[x]);

	return 0;
}