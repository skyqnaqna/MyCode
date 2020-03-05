/*
https://www.acmicpc.net/problem/2217
백준 2217 로프
20/03/05
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; 
vector<int> v;


int main()
{
	
	scanf("%d", &n);

	int w;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &w);
		v.push_back(w);
	}

	sort(v.begin(), v.end(), greater<int>());

	int max(0),weight(0);
	for (int i = 0; i < n; ++i)
	{
		weight = v[i] * (i + 1);
		if (weight > max) max = weight;
	}
	printf("%d\n", max);

	return 0;
}
