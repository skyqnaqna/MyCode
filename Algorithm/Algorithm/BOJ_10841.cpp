/*
백준 10841번 나이순 정렬
20/03/21
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct info
{
	int age;
	string name;
	int order;
}info;

bool cmp(info a, info b)
{
	if (a.age == b.age) return a.order < b.order;
	else return a.age < b.age;
}

int main(void) 
{
	int n;
	scanf("%d", &n);

	vector<info> v;

	info m;
	int t;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> t >> s;
		m.age = t;
		m.name = s;
		m.order = i;
		v.push_back(m);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i].age << " " << v[i].name << "\n";

	return 0;
}
