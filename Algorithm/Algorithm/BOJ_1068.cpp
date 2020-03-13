/*
백준 1068번 트리
https://www.acmicpc.net/problem/1068
20/03/14
*/

#include <iostream>
#include <algorithm>

using namespace std;

void find(int);
void remove(int);

int tree[51];
int n, leaf, root;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < 51; ++i)
		tree[i] = -1;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tree[i]);
		if (tree[i] == -1)
			root = i;
	}
		

	int target;
	scanf("%d", &target);

	if (tree[target] == -1)
	{
		printf("%d\n", 0);
		return 0;
	}

	leaf = 0;
	remove(target);
	find(root);

	printf("%d\n", leaf);

	return 0;
}

void find(int root)
{
	bool isNotLeaf = false;

	for (int i = 0; i < n; ++i)
	{
		if (i == root) continue;
		if (tree[i] != -1 && tree[i] == root)
		{
			isNotLeaf = true;
			find(i);
		}
	}

	if (!isNotLeaf) ++leaf;
}

void remove(int root)
{
	tree[root] = -1;

	for (int i = 0; i < n; ++i)
	{
		if (i == root) continue;
		if (tree[i] == root)
			remove(i);
	}
}
