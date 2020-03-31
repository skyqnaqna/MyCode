/*
백준 1978번 소수 찾기
20/04/01
*/
#include <iostream>

using namespace std;

bool primeNumber[1001] = { false };
int input[100] = { 0 };

int main(void)
{	
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &input[i]);

	for (int i = 2; i <= 1000; ++i)
	{
		for (int j = 2; j <= i; ++j)
		{
			if (j == i) primeNumber[i] = true;
			else if (i % j == 0)
			{
				primeNumber[i] = false;
				break;
			}
			else
				continue;
		}
	}

	int count(0);
	for (int i = 0; i < n; ++i)
	{
		if (input[i] > 1 && primeNumber[input[i]]) ++count;
	}
	printf("%d\n", count);


	return 0;
}
