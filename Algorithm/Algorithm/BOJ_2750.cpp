/*
백준 2750번 수 정렬하기
https://www.acmicpc.net/problem/2750

N개의 수 오름차순으로 정렬하기

19/01/15
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	
	int n;
	cin >> n;

	int *arr = new int [n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}

	delete[]  arr;

	return 0;
}