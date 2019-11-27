#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,u,v,cost,result(0);

int parent[10001];
vector <pair<int, pair<int,int> > > edge;

int getParent(int);
bool cmpSameParent(int,int);
void unionEdge(int,int);
void kruskal();


int main()
{
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &u, &v, &cost);
		edge.push_back(make_pair(cost, make_pair(u,v)));
	}
	
	for (int i = 1; i <= n; ++i)
		parent[i] = i;
	
	sort(edge.begin(),edge.end());
	
	kruskal();
    
   return 0;

}

int getParent(int i)
{
	if (parent[i] == i) return i;
	else return parent[i] = getParent(parent[i]);
}

bool cmpSameParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	
	if ( a == b ) return true;
	else return false;
}

void unionEdge(int u, int v)
{
	u = getParent(u);
	v = getParent(v);

	parent[v] = u;
}

void kruskal()
{
	for (int i = 0; i < m; ++i)
	{
		if (cmpSameParent(edge[i].second.first, edge[i].second.second) == false)
		{
			unionEdge(edge[i].second.first, edge[i].second.second);
			result += edge[i].first;
		}
	}
	
	printf("%d\n", result);
}
