/*
백준 1026번 보물
20/03/20
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
	vector<int> a;
	vector<int> b;

	int n;
	scanf("%d", &n);
	
	int temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		a.push_back(temp);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		b.push_back(temp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int sum(0);
	for (int i = 0; i < n; ++i)
	{
		sum += a[i]*b[i];
	}

	printf("%d\n", sum);
	
	return 0;
}
