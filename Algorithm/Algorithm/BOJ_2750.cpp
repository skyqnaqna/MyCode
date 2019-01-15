/*
백준 2750번 수 정렬하기
https://www.acmicpc.net/problem/2750

N개의 수 오름차순으로 정렬하기
(삽입정렬과 버블정렬)

19/01/15
*/

#include <iostream>
#include <algorithm>

using namespace std;

//버블정렬
int main() {
	int n;
	cin >> n;

	int *arr = new int[n];
	int count = n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	while (count--) {
		for (int i = 0; i < count; i++) {
			int temp = arr[i];
			if (arr[i] > arr[i + 1]) {
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}

	delete[]  arr;
	
	return 0;
}

//삽입정렬
//int main() {
//	int n;
//	cin >> n;
//
//	int *arr = new int[n];
//
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//	for (int i = 1; i < n; i++) {
//		int temp = arr[i]; //삽입위치를 검사할 key를 temp에 저장
//		for (int j = i - 1; j >= 0; j--) { // i번째에서 왼쪽으로 검사하기 때문에 i-1부터 검사
//			if (arr[j] > temp) {
//				arr[j + 1] = arr[j]; //key값보다 크면 오른쪽으로 한 칸 이동시켜줌
//				arr[j] = temp;
//			}
//
//		}
//
//	}
//
//	for (int i = 0; i < n; i++) {
//		cout << arr[i] << "\n";
//	}
//
//	delete[]  arr;
//
//	return 0;
//}

//동적배열
//int main() {
//
//	
//	int n;
//	cin >> n;
//
//	int *arr = new int [n];
//	
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//	sort(arr, arr+n);
//
//	for (int i = 0; i < n; i++) {
//		cout << arr[i] << "\n";
//	}
//
//	delete[]  arr;
//
//	return 0;
//}