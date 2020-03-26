/*
백준 10825번 국영수
20/03/27
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct student
{
	string name;
	int kor;
	int eng;
	int math;
}student;

student st[100001];

bool cmp(const student &a, const student &b)
{
	if (a.kor != b.kor) return a.kor > b.kor;
	else if (a.eng != b.eng) return a.eng < b.eng;
	else if (a.math != b.math) return a.math > b.math;
	else
		return a.name.compare(b.name) < 0;
}

int main(void)
{	
	ios::sync_with_stdio(false);
	int n;
	string s;
	int k, e, m;
	
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> st[i].name >> st[i].kor >> st[i].eng >> st[i].math;
	}

	sort(st, st+n, cmp);

	for (int i = 0; i < n; ++i)
		cout << st[i].name << "\n";

	return 0;
}
