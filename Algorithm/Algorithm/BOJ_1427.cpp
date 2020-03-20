/*
백준 1427번 소트인사이드
20/03/20
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
	int n;
	scanf("%d", &n);

	vector<int> v;

	while (n > 0)
	{
		v.push_back(n % 10);
		n /= 10;
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < v.size(); ++i)
		printf("%d", v[i]);
	printf("\n");
	
	return 0;
}
