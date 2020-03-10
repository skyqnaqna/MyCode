/*
백준 1003번 피보나치 함수
https://www.acmicpc.net/problem/1003
20/03/11
*/

#include <iostream>

using namespace std;

int fz[41];
int fo[41];
int result[100];

int main()
{
	int n;
	scanf("%d", &n);

	fz[0] = 1;
	fo[0] = 0;

	fz[1] = 0;
	fo[1] = 1;

	for (int i = 2; i < 41; ++i)
	{
		fz[i] = fz[i - 1] + fz[i - 2];
		fo[i] = fo[i - 1] + fo[i - 2];
	}

	int temp, index(0);
	while (n--)
	{
		scanf("%d", &temp);
		result[index] = temp;
		++index;
	}

	for (int i = 0; i < index; ++i)
		printf("%d %d\n", fz[result[i]], fo[result[i]]);

	return 0;
}
