/*
���� 2352�� �ݵ�ü ����
https://www.acmicpc.net/problem/2352

��ġ�� �ʰ� ��Ʈ �����ϴ� �ִ� ��
(LIS �˰���)

19/01/21~24
*/

#include <iostream>
#include <algorithm>

using namespace std;

int port[40001] = { 0 };
int selected_port[40001] = { 0 };

int SelectPort(int);

int main() {

	int max_port_num;
	cin >> max_port_num;

	for (int i = 1; i <= max_port_num; ++i) {
		cin >> port[i];
	}

	
	cout << SelectPort(max_port_num) << endl;


	return 0;
}

int SelectPort(const int max_port_num) {
	
	selected_port[1] = port[1];
	int length(1);

	for (int i = 2; i <= max_port_num; ++i) {
		//���� ���� ũ�� �ڿ� �ٿ��ְ� ���̵� 1 ����
		if (selected_port[length] < port[i]) {
			selected_port[++length] = port[i];
			continue;
		}
		//����� ��Ʈ�� �߿��� port[i]���� ũ�ų� ���� ���� ��ġ�� next_port�� ��ȯ
		else {
			int * next_port = lower_bound(selected_port + 1, selected_port + length + 1, port[i]) ;
			*next_port = port[i];
		}

	}


	return length;
}