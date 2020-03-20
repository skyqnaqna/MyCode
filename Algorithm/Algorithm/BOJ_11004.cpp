/*
백준 11004번 K번째 수
20/03/21
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> v;
	int t;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &t);
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	printf("%d\n", v[k - 1]);

	return 0;
}
