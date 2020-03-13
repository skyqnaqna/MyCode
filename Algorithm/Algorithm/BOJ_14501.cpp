/*
백준 14501번 퇴사
https://www.acmicpc.net/problem/14501
20/03/14
*/

#include <iostream>
#include <algorithm>

using namespace std;

int t[17] = { 0 };
int p[17] = { 0 };
int n;

int getProfit(int,int);

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d", &t[i], &p[i]);
	}

	int result = getProfit(1, 0);

	printf("%d\n", result);


	return 0;
}

int getProfit(int i, int sum)
{
	if (i == n + 1)
		return sum;
	else if (i > n)
		return 0;
	else
		return max(getProfit(i + t[i], sum + p[i]), getProfit(i + 1, sum));
}
