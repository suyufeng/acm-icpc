#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

#define N 800005

int n, CC = 0;
string a[N], b[N];
char c[N];
vector<pair<int, int> > ans;

struct node
{
	int son[N][27], cnt = 0;
	int fa[N];
	vector<int> Q[N][2];
	
	void add(int x, int y, int z)
	{
		son[x][z] = y;
		fa[y] = x;
		return ;
	}
	
	void add(string  x, int id, int type)
	{
		int now = 0;
		for(int i = 0; i < x.size(); i++)
		{
			if(!son[now][x[i] - 'a'])
				add(now, ++cnt, x[i] - 'a'), now = cnt;
			else
				now = son[now][x[i] - 'a'];
		}
		Q[now][type].push_back(id);
		return ;	
	}
}

void work()
{
	
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", c);
		a[i] =  c;
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", c);
		b[i] = c;
	}
	for(int i = 1; i <= n; i++)
		add(a[i], i, 1);
	for(int i = 1; i <= n; i++)
		add(b[i], i, 2);
	work();
	printf("%d\n", CC);
	for(int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;	
}
