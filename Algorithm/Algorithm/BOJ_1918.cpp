/*
백준 1918번 후위 표기식
https://www.acmicpc.net/problem/1918
20/03/10
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;

int check(char);

int main()
{
	string s;
	cin >> s;

	string result;
	char op;
	for (int i = 0; i < s.length(); ++i)
	{
		op = s[i];
		if (check(op) < 0) result += op;
		else
		{
			if (st.empty() && op != ')') st.push(op);
			else if (check(st.top()) >= check(op) && check(op) != 0)
			{
				while (!st.empty())
				{
					if (check(st.top()) < check(op)) break;
					if (check(st.top()) == 0) break;
					result += st.top();
					st.pop();
				}
				
				st.push(op);
			}
			else if (op == ')')
			{
				while (st.top() != '(')
				{
					result += st.top();
					st.pop();
				}
				st.pop();
			}
			else st.push(op);
		}
	}


	while (!st.empty())
	{
		char res = st.top();
		result += res;
		st.pop();
	}

	cout << result << endl;
	

	return 0;
}

int check(char c)
{
	if (c == '(') return 0;
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	if (c == ')') return 3;
	else return -1;
}
