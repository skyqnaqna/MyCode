// 기본적인 dfs
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> edge[10001];
bool visit[10001];

void initVisit();
void dfs(int);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, s;
	cin >> n >> m;

	int v, u;
	for (int i = 1; i <= m; ++i)
	{
		cin >> v >> u;
		edge[v].push_back(u);
		edge[u].push_back(v);
	}

	for (int i = 1; i <= n; ++i)
		sort(edge[i].begin(), edge[i].end());

	initVisit();

	for (int i = 1; i <= n; ++i)
	{
		if (visit[i] == false)
			dfs(i);
	}

	return 0;
}

void initVisit()
{
	for (int i = 0; i < 10001; ++i)
		visit[i] = false;

}

void dfs(int v)
{
	if (visit[v] == true) return;

	cout << v << '\n';
	visit[v] = true;

	for (int i = 0; i < edge[v].size(); ++i)
		dfs(edge[v][i]);
	
}