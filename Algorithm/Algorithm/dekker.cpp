#include <iostream>
#include <thread>

using namespace std;

int cnt;
bool flag[2] = { false, false };
int turn;

void func0() {
	for (int i = 0; i < 10000; i++) {
		flag[0] = true;
		while (flag[1] == true) {
			if (turn == 1) {
				flag[0] = false;
				while (turn == 1) {}
				flag[0] = true;
			}
		}

		cout << "func0" << endl;
		cnt++;
		cout << cnt << endl;

		turn = 1;
		flag[0] = false;
		//for (int j = 0; j < 12345; j++) {}
		
	}
}
void func1() {
	for (int i = 0; i < 10000; i++) {
		flag[1] = true;
		while (flag[0] == true) {
			if (turn == 0) {
				flag[1] = false;
				while (turn == 0) {}
				flag[1] = true;
			}
		}


		cout << "func1" << endl;
		cnt++;
		cout << cnt << endl;

		turn = 0;
		flag[1] = false;
	}
}

int main() {
	cout << turn << endl;
	thread t1(func0);
	thread t2(func1);

	t1.join();
	t2.join();

	cout << " cnt :: " << cnt << endl;

	return 0;
}

