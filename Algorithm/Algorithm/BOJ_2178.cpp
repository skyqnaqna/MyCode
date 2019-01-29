/*
백준 2178번 미로탐색
https://www.acmicpc.net/problem/2178

(N*M) 크기의 미로에서 (1,1)에서 시작하여
(N,M)까지의 최단거리 구하기 - BFS

19/01/29
*/

#include <iostream>
#include <queue>

using namespace std;

static int n, m;

int map[100][100] = { 0 };
bool check[100][100] = { false };
int dist[100][100] = { 0 };

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void MakeMap();
void BFS();

int main() {


	MakeMap();
	BFS();


	return 0;
}

void MakeMap() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}

	return;
}

void BFS() {

	typedef pair<int, int> pii;
	queue<pii> q;

	q.push(pii(0, 0));
	check[0][0] = true;
	dist[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		for (int i = 0; i < 4; ++i) {

			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				if (check[next_x][next_y] == false && map[next_x][next_y] == 1) {
					q.push(pii(next_x, next_y));
					check[next_x][next_y] = true;
					dist[next_x][next_y] = dist[x][y] + 1;
				}
			}
		}
		q.pop();
	}

	printf("%d\n", dist[n - 1][m - 1]);

	return;
}