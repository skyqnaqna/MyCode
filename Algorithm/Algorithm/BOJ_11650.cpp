/*
백준 11650번 좌표 정렬하기
20/03/21
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct coordinate
{
	int x;
	int y;
}coordinate;

bool cmp(coordinate a, coordinate b)
{
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

int main(void) 
{
	int n;
	scanf("%d", &n);

	vector<coordinate> v;

	coordinate c;
	int x, y;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &x, &y);
		c.x = x;
		c.y = y;
		v.push_back(c);
	}
	
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i)
	{
		printf("%d %d\n", v[i].x, v[i].y);
	}

	return 0;
}
