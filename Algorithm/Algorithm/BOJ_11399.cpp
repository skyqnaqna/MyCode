// https://www.acmicpc.net/problem/11399
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> v;
priority_queue < int, vector<int>, greater<int> > pq;
int n;

void solution();

int main()
{
	scanf("%d", &n);
	
	int time;
	for (int i =0; i < n; ++i)
	{
		scanf("%d", &time);
//		v.push_back(time);
		pq.push(time);
	}
	/*for (int i = 0; i < n; ++i)
	{
		printf("%d\n", pq.top());
		pq.pop();
	}*/
	solution();
		
	return 0;
}

void solution()
{
	int sum, a;
	
	sum = pq.top();
	a = pq.top();
	pq.pop();
	while (!pq.empty())
	{
		int i = 1;
	
		a += pq.top();
		sum += a;
		pq.pop();
		++i;
	}

	printf("%d\n", sum);
}
