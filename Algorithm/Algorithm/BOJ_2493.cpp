/*
백준 2493번 쇠막대기
https://www.acmicpc.net/problem/2493
20/03/10
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> v;
vector<int> result;
stack<int> st;

int main()
{
	int n;
	scanf("%d", &n);

	v.push_back(0);
	result.assign(n+1, 0);
	
	int num;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &num);
		v.push_back(num);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (st.empty())
		{
			result[i] = 0;
			st.push(i);
		}
		else
		{
			while (1)
			{
				if (v[i] < v[st.top()])
				{
					result[i] = st.top();
					st.push(i);
					break;
				}
				else
					st.pop();

				if (st.empty())
				{
					result[i] = 0;
					st.push(i);
					break;
				}
			}
			
		}
	}

	for (int i = 1; i <= n; ++i)
		printf("%d ", result[i]);
	printf("\n");
		

	return 0;
}
