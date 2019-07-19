// º° Âï±â - 10
// https://www.acmicpc.net/problem/2447
// 07.19

#include <iostream>
#include <string>

using namespace std;

string MakeStars(string s)
{
	string result;

	for (int i = 1; i <= 9; ++i)
	{
		if (i == 5)
		{
			result += " ";
			continue;
		}
		result += s;
		if (i == 3 || i == 6) result += "\n";
		
	}

	return result;
}

int main()
{

	string s = "*";

	//cout << s << endl;

	int k;
	cin >> k;
	
	for (int i = 0; i < k; ++i)
	{
		s = MakeStars(s);
	}

	cout << s << endl;

	return 0;
}