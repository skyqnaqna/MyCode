/*
백준 10989번 수 정렬하기
https://www.acmicpc.net/problem/10989

N개의 수 오름차순으로 정렬하기
(기수정렬과 계수정렬)

19/01/16
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int *arr = new int[n];
	int big_num = 0;
	int digits = 1;
	vector<vector<int>>v(10);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > big_num) big_num = arr[i];
	}

	while (digits <= big_num) { //제일 큰 수의 자리수보다 한자리수 더 큰 10의 제곱수 구하기
		digits *= 10;
	}

	for (int i = 1; i <= digits; i *= 10) { // i는 자리수
		for (int j = 0; j < n; j++) {		// 자리수 기준으로 각 숫자에 해당하는 v배열에 넣기
			int k = (arr[j] % (i * 10)) / i;
			v[k].push_back(arr[j]);
		}
		while (!v.empty()) {
			int k = 0;
			for (int i = 0; i <= 9; i++) {

				reverse(v[i].begin(), v[i].end());

				while (!v[i].empty()) {

					arr[k] = v[i].back();
					v[i].pop_back();
					k++;
					if (k == n) break;
				}
				if (k == n) break;
			}
			if (k == n) break;
		}


	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}




	delete[] arr;

	return 0;
}