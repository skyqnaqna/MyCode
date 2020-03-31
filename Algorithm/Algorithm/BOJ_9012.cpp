/*
백준 9012번 Parenthesis
20/04/01
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{	
	int n;
	cin >> n;

	stack<char> st;
	string s;
	vector<string> v;

	while (n--)
	{
		cin >> s;
		int size = s.length();
		
		while (!st.empty())
			st.pop();

		for (int i = 0; i < size; ++i)
		{
			if (s[i] == '(') st.push(s[i]);
			else if (s[i] == ')')
			{
				if (st.empty()) st.push(s[i]);
				else if (st.top() == '(') st.pop();
			}
		}

		if (st.empty()) v.push_back("YES");
		else v.push_back("NO");
	}

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << '\n';

	return 0;
}
