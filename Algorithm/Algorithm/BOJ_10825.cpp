/*
백준 10825번 국영수
20/03/27
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct student
{
	string name;
	int kor;
	int eng;
	int math;
}student;

vector<student> v;

bool cmp(student a, student b)
{
	if (a.kor != b.kor) return a.kor > b.kor;
	else if (a.eng != b.eng) return a.eng < b.eng;
	else if (a.math != b.math) return a.math > b.math;
	else
		return a.name.compare(b.name) < 0;
}

int main(void)
{	
	int n;
	string s;
	int k, e, m;
	student st;

	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> k >> e >> m;
		st.name = s;
		st.kor = k;
		st.eng = e;
		st.math = m;
		v.push_back(st);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; ++i)
		cout << v[i].name << "\n";

	return 0;
}
