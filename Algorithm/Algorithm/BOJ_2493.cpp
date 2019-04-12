/*
���� 2493�� ž
https://www.acmicpc.net/problem/2493

������ ž���� �������� �߻��� �������� ��� ž����
�����ϴ����� ����϶�

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