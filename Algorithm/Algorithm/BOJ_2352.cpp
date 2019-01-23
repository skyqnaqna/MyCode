/*
백준 2352번 반도체 설계
https://www.acmicpc.net/problem/2352

겹치지 않게 포트 연결하는 최대 수
(LIS 알고리즘)

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
		//다음 수가 크면 뒤에 붙여주고 길이도 1 증가
		if (selected_port[length] < port[i]) {
			selected_port[++length] = port[i];
			continue;
		}
		//연결된 포트들 중에서 port[i]보다 크거나 같은 곳의 위치를 next_port에 반환
		else {
			int * next_port = lower_bound(selected_port + 1, selected_port + length + 1, port[i]) ;
			*next_port = port[i];
		}

	}


	return length;
}