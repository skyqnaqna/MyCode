#include <iostream>
#include <thread>

using namespace std;

int cnt;
bool flag[2] = { false, false };
int turn = 0;

void func0() {
	for (int i = 0; i < 10000; i++) {
		flag[0] = true;
		turn = 1;
		while (flag[1] == true && turn == 1) {}

		cnt++;
		printf("cnt1 :: %d\n", cnt);

		flag[0] = false;
	}
}
void func1() {
	for (int i = 0; i < 10000; i++) {
		flag[1] = true;
		turn = 0;
		while (flag[0] == true && turn == 0) {}

		cnt++;
		printf("cnt2 :: %d\n", cnt);

		flag[1] = false;
	}
}

int main() {
	thread t1(func0);
	thread t2(func1);

	t1.join();
	t2.join();

	cout << "cnt : :" << cnt << endl;

	return 0;
}
