/*
���� 1697�� ���ٲ���
https://www.acmicpc.net/problem/1697


19/02/01
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visit[100001] = { false };

//�� �Ÿ��� �ش��ϴ� ������ �ִ� ����
//���� �־��� ���� �Ÿ��� 17�� ���� ����
//ex) v[2] : �Ÿ��� 2�� ������ ����
vector<vector<int> > v(17);

int main() {

	int n, k;
	cin >> n >> k;

	int count(0); //�Ÿ�

	v[0].push_back(n);
	visit[n] = true;
	bool isFind(false);

	while (!isFind) {
		if (n == k) break;
		++count;

		for (int i = 0; i < v[count - 1].size(); ++i) {
			if ((v[count - 1].at(i) - 1) == k) {
				isFind = true;
			}
			else if (visit[v[count - 1].at(i) - 1] == false) {
				v[count].push_back(v[count - 1].at(i) - 1);
				visit[v[count - 1].at(i) - 1] = true;
			}

			if ((v[count - 1].at(i) + 1) == k) {
				isFind = true;
			}
			else if (visit[v[count - 1].at(i) + 1] == false) {
				v[count].push_back(v[count - 1].at(i) + 1);
				visit[v[count - 1].at(i) + 1] = true;
			}


			if ((v[count - 1].at(i) * 2) == k) {
				isFind = true;
			}
			else if (visit[v[count - 1].at(i) * 2] == false) {
				v[count].push_back(v[count - 1].at(i) * 2);
				visit[v[count - 1].at(i) * 2] = true;
			}


		}

		v[count - 1].clear();



	}

	cout << count << endl;

	return 0;
}