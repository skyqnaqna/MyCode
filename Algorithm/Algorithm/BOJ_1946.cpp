/*
백준 1946번 신입 사원
https://www.acmicpc.net/problem/1946
20/03/12
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;
int result[21];

int main()
{
	int t, n, count;
	scanf("%d", &t);

	int T = t;

	while (T--)
	{
		scanf("%d", &n);
		v.assign(n, pair<int,int>(0,0));

		int a, b;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &a, &b);
			v.push_back(pair<int,int>(a, b));
		}

		sort(v.begin(), v.end(), greater<pair<int,int>>());

		count = n;

		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (v[i].second > v[j].second)
				{
					--count;
					break;
				}
			}
		}

		result[t - T - 1] = count;

	}
	
	for (int i = 0; i < t; ++i)
		printf("%d\n", result[i]);
	

	return 0;
}
