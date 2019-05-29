int main() {
	int flag[2] = { false };
	int i,
		j,
		turn;

	//Process i
	do {
		flag[i] = true;
		while (flag[i]) {
			if (turn == j) {
				flag[i] == false;
				while (turn == j)
					;/* do nothing */
				flag[i] = true;
			}
		}

		/* critical section */
		turn = j;
		flag[i] = false;
		/* remainder section */
	} while (true);

	//Process j
	do {
		flag[j] = true;
		while (flag[j]) {
			if (turn == i) {
				flag[j] == false;
				while (turn == i)
					;/* do nothing */
				flag[j] = true;
			}
		}

		/* critical section */
		turn = i;
		flag[j] = false;
		/* remainder section */
	} while (true);

}