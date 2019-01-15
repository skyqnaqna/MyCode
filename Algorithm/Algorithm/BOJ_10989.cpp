/*
���� 10989�� �� �����ϱ�
https://www.acmicpc.net/problem/10989

N���� �� ������������ �����ϱ�
(������İ� �������)

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

	while (digits <= big_num) { //���� ū ���� �ڸ������� ���ڸ��� �� ū 10�� ������ ���ϱ�
		digits *= 10;
	}

	for (int i = 1; i <= digits; i *= 10) { // i�� �ڸ���
		for (int j = 0; j < n; j++) {		// �ڸ��� �������� �� ���ڿ� �ش��ϴ� v�迭�� �ֱ�
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