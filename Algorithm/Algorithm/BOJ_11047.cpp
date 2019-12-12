// https://www.acmicpc.net/problem/11047
// n가지 종류의 동전으로 금액 k를 만족시키는 동전수의 최솟값 구하기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int>v;
	int x[10] = {0};
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	int coin;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &coin);
		v.push_back(coin);
	}
	
	sort(v.begin(), v.end(), greater<int>());
	
	int result(0);
	for (int i = 0; i < n; ++i)
	{
		if (v[i] > k)
			continue;
		x[i] = k / v[i];
		k -= x[i]*v[i];
		
		result += x[i];
		if (k == 0)
			break;
	}
	
	printf("%d\n", result);	
    
    return 0;

}
