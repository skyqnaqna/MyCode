/*
백준 2493번 탑
https://www.acmicpc.net/problem/2493

각각의 탑에서 왼쪽으로 발사한 레이저가 어느 탑에서
수신하는지를 출력하라

19/04/12
*/

#include <iostream>

using namespace std;

void GetReceivableTower(const int);

int tower[500001] = { 0 };

int main()
{
	static int n;
	cin >> n;


	for (int i = 1; i <= n; i++)
	{
		cin >> tower[i];
	}

	GetReceivableTower(n);

	for (int i = 1; i <= n; ++i)
	{
		cout << tower[i] << " ";
	}
	cout << endl;

	return 0;
}

void GetReceivableTower(const int n)
{
	if (n == 1)
	{
		tower[n] = 0; 
		return;
	}
	
	for (int i = n-1; i > 0; --i)
	{
		if (tower[n] <= tower[i])
		{
			tower[n] = i;
			GetReceivableTower(n - 1);
			return;
		}
		
	}
	tower[n] = 0;
	GetReceivableTower(n - 1);
	return;
}