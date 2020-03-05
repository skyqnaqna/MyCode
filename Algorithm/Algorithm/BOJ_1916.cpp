/*
백준 1916 최소비용 구하기
https://www.acmicpc.net/problem/1916
*/

#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int n, m, s, e;
priority_queue< pair<int, int>> pq;
vector <pair<int, int>> map[1001];

vector<int> dijkstra(int s, int n);

int main()
{
	scanf("%d %d", &n, &m);
	++n;

	for (int i = 0; i < m; ++i)
	{
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		map[start].push_back(make_pair(end, cost));
	}
		
	scanf("%d %d", &s, &e);

	vector<int> result = dijkstra(s, n);

	printf("%d\n", result[e]);

	return 0;
}

vector<int> dijkstra(int s, int n)
{
	vector<int> dist(n, INF);
	dist[s] = 0;

	pq.push(make_pair(0, s));

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (dist[u] < cost) continue;

		for (int i = 0; i < map[u].size(); ++i)
		{
			int v = map[u][i].first;
			int vDist = cost + map[u][i].second;

			if (dist[v] > vDist)
			{
				dist[v] = vDist;
				pq.push(make_pair(vDist, v));
			}
		}

	}

	return dist;
}