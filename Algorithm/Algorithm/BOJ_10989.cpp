/*
백준 10989번 수 정렬하기3
https://www.acmicpc.net/problem/10989
20/03/11
*/

#include <iostream>

using namespace std;

int arr[10001];

int main()
{
	int n;
	scanf("%d", &n);

	int temp, max(0);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		++arr[temp];
		if (temp > max) max = temp;
	}

	int count;
	for (int i = 1; i <= max; ++i)
	{
		count = arr[i];
		if (count == 0) continue;

		while (count--)
			printf("%d\n", i);
	}

	
	return 0;
}
