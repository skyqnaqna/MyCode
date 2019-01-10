/*
백준 2309번 일곱 난쟁이
https://www.acmicpc.net/problem/2309

일곱 난쟁이들의 키의 합이 100
9명중 일곱 난쟁이들을 찾아라

19/01/07

*/

#include <iostream>
#include <algorithm>

using namespace std;

int dwarf[9] = { 0 };

int sum_height = 0;

void input_height();
void sum_height_all();
void pick_dwarf();
void result(int, int);

int main() {
	input_height();
	sum_height_all();
	pick_dwarf();
	return 0;
}

void input_height() {
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		if (dwarf[i] >= 100) {
			cout << "100미만의 자연수를 입력할 것" << "\n";
			return;
		}
	}
}

void sum_height_all() {
	for (int all_dwarf : dwarf) {
		sum_height += all_dwarf;
	}
}

void pick_dwarf() {
	int not_dwarf_height = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j) break;

			not_dwarf_height = dwarf[i] + dwarf[j];

			if (sum_height - not_dwarf_height == 100) {
				result(i, j);
			}
		}
	}
}

void result(int a, int b) {
	dwarf[a] = 100;
	dwarf[b] = 100;

	sort(dwarf, dwarf + 9);

	for (int i = 0; i < 7; i++) {
		cout << dwarf[i] << "\n";
	}
}