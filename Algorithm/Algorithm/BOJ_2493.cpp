/*
���� 2493�� ī�� �����ϱ�
https://www.acmicpc.net/problem/2493

������ ž���� �������� �߻��� �������� ��� ž����
�����ϴ����� ����϶�

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