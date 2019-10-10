/*
백준 1629번 곱셈
https://www.acmicpc.net/problem/1629
자연수 A를 B번 곱한수를 C로 나눈 나머지를 구하자
*/

#include <iostream>

using namespace std;

long long mul(long long a, long long b, long long &c);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b, c;

	cin >> a >> b >> c;

	cout << mul(a%c, b, c) << '\n';

	return 0;
}

long long mul(long long a, long long b, long long &c)
{
	if (b == 1)
		return a%c;
	else
	{
		long long temp = (mul(a, b / 2, c)%c);
		if (b % 2 == 0)
			return (temp*temp) % c;
		else
			return (((temp*temp)%c)*a)%c; // temp*temp가 범위를 초과할 수 있으므로 꼭 %c 해줘야함
	}
}