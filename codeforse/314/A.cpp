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
int team[N], cnt = 1, deep[N];
vector<int> have[N][2];

struct node
{
	int son[N][27];
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
		int now = 1;
		for(int i = 0; i < x.size(); i++)
		{
			if(!son[now][x[i] - 'a'])
				add(now, ++cnt, x[i] - 'a'), now = cnt;
			else
				now = son[now][x[i] - 'a'];
		}
		Q[now][type].push_back(id);
		//printf("%d\n",now);
		return ;	
	}
}T;

void work()
{
	int head = 0, tail = 1;
	team[1] = 1; deep[1] = 0;
	//printf("%d\n", cnt);
	while(head < tail)
	{
		int u = team[++head];
		for(int i = 0; i < 26; i++)
			if(T.son[u][i])
				team[++tail] = T.son[u][i], deep[team[tail]] = deep[u] + 1;
	}
	int all = tail;
	reverse(team + 1, team + 1 + all);
	for(int i = 1; i <= all; i++)
	{
		int now = team[i];
		for(int id = 0; id <= 1; id++)
			for(int j = 0; j < have[now][id].size(); j++)
				T.Q[now][id].push_back(have[now][id][j]);
	//	printf("%d %d\n", now, T.Q[now][0].size() + T.Q[now][1].size());
		int st1, st2;
		for(st1 = 0, st2 = 0; st1 < T.Q[now][0].size() && st2 < T.Q[now][1].size(); st1++, st2++)
			ans.push_back(make_pair(T.Q[now][0][st1], T.Q[now][1][st2])), CC += deep[now];
		for(; st1 < T.Q[now][0].size(); st1++)
			have[T.fa[now]][0].push_back(T.Q[now][0][st1]);
		for(; st2 < T.Q[now][1].size(); st2++)
			have[T.fa[now]][1].push_back(T.Q[now][1][st2]);
		have[now][0].clear(); have[now][1].clear();
		T.Q[now][0].clear(); T.Q[now][1].clear();
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", c);
		a[i] =  c;
		cout << a[i] << endl;
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", c);
		b[i] = c;
	}
	for(int i = 1; i <= n; i++)
		T.add(a[i], i, 0);
	for(int i = 1; i <= n; i++)
		T.add(b[i], i, 1);
	work();
	printf("%d\n", CC);
	for(int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;	
}
