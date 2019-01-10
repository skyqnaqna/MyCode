/*
백준 14500번 테트로미노
https://www.acmicpc.net/problem/14500

1*1크기의 칸으로 나뉜, 크기가 N*M인 종이 위에 각 칸마다 정수가 쓰여있다.
이 때 테트로미노를 놓았을 때 그 칸에 적힌 정수들의 합의 최댓값을 출력한다.

19/01/09
*/

#include <iostream>

using namespace std;

int map[500][500] = { 0 };

int main() {
	int n, m;
	int max_sum = 0;
	int temp_sum = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j + 3 < m) {
				temp_sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 3 < n) {
				temp_sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 1 < n && j + 1 < m) {
				temp_sum = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 2 < n && j + 1 < m) {
				temp_sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 1 < n && j + 2 < m) {
				temp_sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 2 < n && j + 1 < m) {
				temp_sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i - 1 >= 0 && j + 2 <m) {
				temp_sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 2 < n && j + 1 <m) {
				temp_sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 1 < n && j + 2 < m) {
				temp_sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 2 < n && j - 1 >= 0) {
				temp_sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 1 < n && j + 2 < m) {
				temp_sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 2 < n && j + 1 < m) {
				temp_sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i - 1 >= 0 && j + 1 < m) {
				temp_sum = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 1][j + 2];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 2 < n && j - 1 >= 0) {
				temp_sum = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 1 < n && j + 2 < m) {
				temp_sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i - 1 >= 0 && j + 2 < m) {
				temp_sum = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i][j + 2];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 2 < n && j + 1 < m) {
				temp_sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 1 < n && j + 2 < m) {
				temp_sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i][j + 2];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}

			if (i + 2 < n && j - 1 >= 0) {
				temp_sum = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j];
				if (max_sum < temp_sum) max_sum = temp_sum;
			}
		}
	}

	cout << max_sum << "\n";

	return 0;
}