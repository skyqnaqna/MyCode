/*
백준 11724번 연결 요소(Connected Component)의 개수 구하기
https://www.acmicpc.net/problem/11724
*/

#include <iostream>

using namespace std;

int map[1001][1001] = { 0 };
bool visit[1001] = { false };
int n, m;

void dfs(int);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int i,u,v;
	for (i = 0; i < m; ++i)
	{
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}

	int count = 0;
	for (i = 1; i <= n; ++i)
	{
		if (visit[i] == false)
		{
			dfs(i);
			++count;
		}
	}

	cout << count << endl;
	return 0;
}

void dfs(int v)
{
	visit[v] = true;

	int i;
	for (i = 1; i <= n; ++i)
	{
		if (map[v][i] == 1 && visit[i] == false)
			dfs(i);
	}
}