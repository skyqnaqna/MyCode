// https://www.acmicpc.net/problem/1931
// 백준 1931 회의실배정
// 20/03/05

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting
{
	int start;
	int finish;
};

bool compare(const meeting& m1, const meeting& m2)
{
	if (m1.finish == m2.finish)
		return m1.start < m2.start;
	return m1.finish < m2.finish;
}

int main()
{
	int n;
	scanf("%d", &n);

	vector<meeting>v;
	meeting times;

	int startTime, finishTime;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &startTime, &finishTime);
		times.start = startTime;
		times.finish = finishTime;
		v.push_back(times);
	}

	sort(v.begin(), v.end(), compare);

	/*for (int i = 0; i < n; ++i)
		printf("(%d %d)\n",v[i].start,v[i].finish);
	printf("\n");*/

	int count(1);
	int fTime = v[0].finish;

	for (int i = 1; i < n; ++i)
	{
		if (v[i].start < fTime) continue;
		else
		{
			++count;
			fTime = v[i].finish;
			//printf("%d %d\n", v[i].start, v[i].finish);
		}
	}
	
	printf("%d\n", count);

	return 0;
}
