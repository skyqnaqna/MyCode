/*
백준 2941번 크로아티아 알파벳
https://www.acmicpc.net/problem/2941

크로아티아 알파벳 몇 개인지 출력하기

19/01/21
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string input_alphabet;
	cin >> input_alphabet;

	int alphabet_length = input_alphabet.length();
	int croatia_alphabet(alphabet_length);
	
	for (int i = 0; i < alphabet_length; i++) {
		
		if (input_alphabet[i] == '-' || input_alphabet[i] == '=') {
			croatia_alphabet--;
			
			if (input_alphabet[i - 1] == 'z'&&input_alphabet[i - 2] == 'd') {
				croatia_alphabet--;
			}
		}
		else if (input_alphabet[i] == 'j') {
			
			if (input_alphabet[i - 1] == 'l' || input_alphabet[i - 1] == 'n') {
				croatia_alphabet--;
			}
		}
		
	}

	cout << croatia_alphabet << "\n";

	return 0;
}