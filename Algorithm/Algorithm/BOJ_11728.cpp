/*
백준 11728번 배열 합치기
https://www.acmicpc.net/problem/11728
정렬되어 있는 두 배열 A와 B를 합친 다음 정렬해서 출력하기
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int>q_a, q_b;
vector<int>v;

void init(int &a, int &b);
void sorting();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int size_A, size_B, i;

	cin >> size_A; cin >> size_B;

	int size_C = size_A + size_B;

	init(size_A, size_B);
	sorting();

	for (auto &e : v)
		cout << e << " ";
	cout << '\n';

	
	return 0;
}

void init(int &a, int &b)
{
	int i(0);
	while (a-- > 0)
	{
		cin >> i;
		q_a.push(i);
	}

	while (b-- > 0)
	{
		cin >> i;
		q_b.push(i);
	}
}

void sorting()
{
	while (!q_a.empty() && !q_b.empty())
	{
		if (q_a.front() > q_b.front())
		{
			v.push_back(q_b.front());
			q_b.pop();
		}
		else if (q_a.front() < q_b.front())
		{
			v.push_back(q_a.front());
			q_a.pop();
		}
		else if (q_a.front() == q_b.front())
		{
			v.push_back(q_a.front());
			v.push_back(q_b.front());
			q_a.pop();
			q_b.pop();
		}
	}

	if (q_a.empty())
	{
		while (!q_b.empty())
		{
			v.push_back(q_b.front());
			q_b.pop();
		}
	}
	else if (q_b.empty())
	{
		while (!q_a.empty())
		{
			v.push_back(q_a.front());
			q_a.pop();
		}
	}

}