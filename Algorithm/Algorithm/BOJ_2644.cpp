/*
백준 2644 촌수계산
주어진 두 사람의 촌수를 계산하기
https://www.acmicpc.net/problem/2644
*/

#include <iostream>
#include <vector>

using namespace std;

int map[101][101] = { 0 };
bool visit[101] = { false };
vector<int> edge[101];
int n, p1, p2, m, result(0);
bool isFind = false;

void dfs(int, int);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> p1 >> p2 >> m;

	int i,u(0),v(0);
	for (i = 0; i < m; ++i)
	{
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	
	dfs(p1,0);

	if (isFind) cout << result << '\n';
	else cout << -1 << '\n';
	
	return 0;
}

void dfs(int v, int c)
{
	if (visit[v] == true) return;

	visit[v] = true;
	int dist = ++c;
	
	if (v == p2)
	{
		isFind = true;
		result = dist - 1;
		return;
	}
	else 
	{
		int i;
		for (i = 0; i < edge[v].size(); ++i)
		{
			dfs(edge[v][i], dist);
		}
		

	}
	
	
}