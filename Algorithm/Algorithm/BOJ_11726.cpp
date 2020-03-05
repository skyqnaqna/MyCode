/*
���� 11726 2xn Ÿ�ϸ�
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
		// ���������� �־���� �����÷� �ȳ�
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	printf("%d\n", dp[n]);

	return 0;
}