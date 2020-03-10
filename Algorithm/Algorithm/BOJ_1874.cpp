/*
백준 1874번 스택 수열
https://www.acmicpc.net/problem/1874
20/03/10
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

stack<int> st;
vector<int> v;
string s;

int main()
{
	int n;
	scanf("%d", &n);

	int num;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &num);
		v.push_back(num);
	}

	int k, m(1);

	for (int i = 0; i < n; ++i)
	{
		k = v[i];

		if (st.empty() && m <= k)
		{
			while (m <= k)
			{
				st.push(m);
				s += '+';
				++m;
			}

			if (st.top() == k)
			{
				st.pop();
				s += '-';
			}
		}
		else if (st.top() == k)
		{
			st.pop();
			s += '-';
		}
		else if (st.top() < k)
		{
			while (st.top() < k)
			{
				st.push(m);
				s += '+';
				++m;
			}
			st.pop();
			s += '-';
		}
		else if (st.top() > k)
		{
			printf("NO\n");
			return 0;
		}
	}

	for (int i = 0; i < s.length(); ++i)
	{
		printf("%c\n", s[i]);
	}


	return 0;
}
