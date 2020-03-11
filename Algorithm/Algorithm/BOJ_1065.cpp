/*
백준 1065번 한수
https://www.acmicpc.net/problem/1065
20/03/12
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int count(0);
	
	if (n < 100)
	{
		printf("%d\n", n);
	}
	else
	{
		int first, scnd, third;
		for (int i = 100; i <= n; ++i)
		{
			first = i % 10;
			scnd = (i / 10) % 10;
			third = i / 100;

			if (first - scnd == scnd - third)
				++count;
		}
		printf("%d\n", count + 99);
	}
	

	return 0;
}
