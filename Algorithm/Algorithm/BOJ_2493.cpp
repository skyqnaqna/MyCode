/*
백준 2493번 카드 구매하기
https://www.acmicpc.net/problem/2493

각각의 탑에서 왼쪽으로 발사한 레이저가 어느 탑에서
수신하는지를 출력하라

19/04/12
*/

#include <iostream>

using namespace std;

void GetReceiveTower(const int);

int tower[500001] = { 0 };

int main()
{
	static int n;
	cin >> n;


	for (int  i = 1; i <= n; i++)
	{
		cin >> tower[i];
	}

	GetReceiveTower(n);


	delete[] tower;

	return 0;
}

void GetReceiveTower(const int n)
{
	for (int i = n-1; i > 0; --i)
	{
		if (tower[n] <= tower[i])
		{

		}
	}
}