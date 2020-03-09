/*
백준 10799번 쇠막대기
https://www.acmicpc.net/problem/10799
20/03/09
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main()
{
	string s;
	cin >> s;

	stack<char> st;
	int result(0);

	for (int i = 0; i < s.length(); ++i)
	{
		char c = s[i];

		if (c == '(')
			st.push(s[i]);
		else
		{
			if (s[i - 1] == '(')
			{
				st.pop();
				result += st.size();
			}
			else
			{
				st.pop();
				result += 1;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
