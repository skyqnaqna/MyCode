/*
백준 2352번 반도체 설계
https://www.acmicpc.net/problem/2352



19/01/21
*/

#include <iostream>
#include <vector>

using namespace std;

int port[40001] = { 0 };
vector<int>dp;

int GetDp(int);

int main() {

	int max_port_num;
	cin >> max_port_num;

	for (int i = 1; i <= max_port_num; ++i) {
		cin >> port[i];
	}

	int result = GetDp(max_port_num);

	cout << result << endl;


	return 0;
}

int GetDp(const int max_port_num) {
	int max(0);
	dp.push_back(0);
	dp.push_back(port[1]);

	for (int i = 2; i <= max_port_num; ++i) {
		for (int j = 1; j <= dp.size(); ++j) {
			if (port[i] < dp.at(j) && port[i] > dp.at(j - 1)) {
				dp.at(j) = port[i];
			}
			else if (port[i] > dp.back()) {
				dp.push_back(port[i]);
			}
		}
	}

	return dp.size();
}