/*
백준 11052번 카드 구매하기
https://www.acmicpc.net/problem/11052

구매하려는 카드 개수 N장
P[i] 는 i장 들어있는 팩의 가격
N장 구매할 때 최대 금액은?

19/02/12
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int card_num;
	cin >> card_num;
	int &N = card_num;

	int *price = new int[N+1];
	int *dp = new int[N + 1]{ 0 };

	for (int i = 1; i <= N; ++i) {
		cin >> price[i];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] = max(price[j] + dp[i - j], dp[i]);
		}
	}

	cout << dp[N] << endl;

	delete[] price;
	delete[] dp;

	return 0;
}