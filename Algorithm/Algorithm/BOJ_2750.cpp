/*
���� 2750�� �� �����ϱ�
https://www.acmicpc.net/problem/2750

N���� �� ������������ �����ϱ�
(�������İ� ��������)

19/01/15
*/

#include <iostream>
#include <algorithm>

using namespace std;

//��������
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

//��������
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
//		int temp = arr[i]; //������ġ�� �˻��� key�� temp�� ����
//		for (int j = i - 1; j >= 0; j--) { // i��°���� �������� �˻��ϱ� ������ i-1���� �˻�
//			if (arr[j] > temp) {
//				arr[j + 1] = arr[j]; //key������ ũ�� ���������� �� ĭ �̵�������
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

//�����迭
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