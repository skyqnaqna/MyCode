/*
백준 1181번 단어 정렬
20/03/21
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
	if (a.length() == b.length())
	{
		return (a.compare(b) < 0);
	}
	else return a.length() < b.length();
}

int main(void) 
{
	int n;
	scanf("%d", &n);

	vector<string> v;

	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i)
	{
		if (i > 0 && v[i] == v[i - 1]) continue;
		else cout << v[i] << endl;
	}

	return 0;
}
