#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cassert>

using namespace std;

#define N 100005

vector<pair<int, int> > E[N];
map<pair<int, int> , int> bel;
vector<int> edge[N];

int ans[N], used[N], color[N], f[N];
int team[N], lzj = 0, belong[N];
pair<int, int> a[N];
vector<int> block;

void dfs(int x)
{
	block.push_back(x);
	used[x] = lzj;
	for(int i = 0; i < edge[x].size(); i++)
	{
		int to = edge[x][i];
		if(used[to] == lzj) continue;
		dfs(to);
	}
	return ;
}

int find(int x)
{
	if(f[x] == x) return f[x];
	f[x] = find(f[x]);
	return f[x];
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m, Maxcolor = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int p, q, t;
		scanf("%d%d%d", &p, &q, &t);
		E[t].push_back(make_pair(p, q));
		Maxcolor = max(Maxcolor, t);
	}
	int limit = 1;
	for(;limit * limit <= m; limit++);
	int Q;
	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++)
	{	
		int p, q;
		scanf("%d%d", &p, &q);
		if(p > q) swap(p, q);
		if(bel.count(make_pair(p, q)))
			belong[i] = bel[make_pair(p, q)];
		else
			bel[make_pair(p, q)] = belong[i] = i;
		a[i] = make_pair(p, q);
	}	
	for(int i = 1; i <= Maxcolor; i++)
	{
		if(E[i].size() > limit)
		{
		//	if(n > 10000) assert(false);
			for(int j = 1; j <= n; j++)
				f[j] = j;
			for(int j = 0; j < E[i].size(); j++)
			{
				int st = E[i][j].first, ed = E[i][j].second;
				st = find(st), ed = find(ed);
				if(st == ed) continue;
				f[ed] = st;
			}
			for(int j = 1; j <= m; j++)
			{
				if(belong[j] == j)
					if(find(a[j].first) == find(a[j].second))
						ans[j] ++;
			}
		}
		else
		{
			lzj ++;
			vector<int> seq;
			for(int j = 0; j < E[i].size(); j++)
				seq.push_back(E[i][j].first), seq.push_back(E[i][j].second);
			for(int j = 0; j < seq.size(); j++)
				edge[seq[j]].clear();
			for(int j = 0; j < E[i].size(); j++)
				edge[E[i][j].first].push_back(E[i][j].second),
				edge[E[i][j].second].push_back(E[i][j].first);
			for(int j = 0; j < seq.size(); j++)
			{
				int now = seq[j];
				if(used[now] == lzj) continue;
				block.clear();
				dfs(seq[j]);
				for(int S = 0; S < block.size(); S++)
					for(int T = S + 1; T < block.size(); T++)
					{
						int st = block[S],ed = block[T];
						if(st > ed) swap(st, ed); 
						if(bel.count(make_pair(st, ed)))
							ans[bel[make_pair(st, ed)]] ++;
					}
			}
		}
	}
	for(int i = 1; i <= Q; i++)
		printf("%d\n", ans[belong[i]]);
	return 0;
}
