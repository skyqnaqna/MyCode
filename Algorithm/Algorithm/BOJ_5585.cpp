#include <iostream>
#include <algorithm>

using namespace std;

int coin[6] = {500, 100, 50, 10, 5, 1};
int x[6] = {0};
int remain;

int main()
{
	scanf("%d", &remain);
	
	remain = 1000 - remain;
	
	for (int i = 0; i < 6; ++i)
	{
		if (coin[i] > remain)
			continue;
		x[i] = remain / coin[i];
		remain -= x[i]*coin[i];
		if (remain == 0)
			break;
	}
	
   int result(0);
   for (int i = 0; i < 6; ++i)
   	 result += x[i];
	printf("%d\n", result);
	
    return 0;

}
