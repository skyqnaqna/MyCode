/*
백준 11726 2xn 타일링
https://www.acmicpc.net/problem/11726
*/

#include <iostream>

using namespace std;

int dp[1001] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		// 나머지값을 넣어줘야 오버플로 안남
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	printf("%d\n", dp[n]);

	return 0;
}