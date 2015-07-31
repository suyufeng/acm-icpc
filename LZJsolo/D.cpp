#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

#define N 100005
#define PI pair<int, int>

typedef long long LL;
#define MP make_pair
int a[N], f[N], num[N], start[N], tot = 0;
int visit[N], lzj = 0;
bool exist[N];
struct Road
{
	int x[N << 1], y[N << 1], next[N << 1];
}r;

void build(int x, int y)
{
	tot++;
	r.x[tot] = x, r.y[tot] = y, r.next[tot] = start[x], start[x] = tot;
}

PI p[N];

int find(int x)
{
	if(x == f[x]) return f[x];
	f[x] = find(f[x]);
	return f[x];
}

int main()
{
	int n, m;
	LL CC = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		f[i] = i, num[i] = 1;
	for(int i = 1; i <= m; i++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		build(p, q); build(q, p);
	}
	for(int i = 1; i <= n; i++)
		p[i] = MP(a[i], i);
	sort(p + 1, p + 1 + n);
	reverse(p + 1, p + 1 + n);
	for(int i = 1; i <= n; i++)
	{
		vector<int> seq;
		seq.clear();
		int now = p[i].second, sum = 0;
		lzj ++;
		for(int j = start[now]; j; j = r.next[j])
		{
			int to = r.y[j];
			if(!exist[to]) continue;
			int fa = find(to);
			if(visit[fa] == lzj) continue;
			visit[fa] = lzj; sum += num[fa]; 
			seq.push_back(to);
		}
		//printf("%d %d\n", now, (int)seq.size());
		for(int j = 0; j < seq.size(); j++)
		{
			int to = seq[j];
			int fa = f[to];
	 		CC += (LL)num[fa] * (LL)(sum - num[fa] + 2) * p[i].first;
			f[fa] = now; num[now] += num[fa]; 
	 	}
	 	exist[now] = true;
	 }
	 printf("%.10f\n", CC / ((double)n * (n - 1)));
	 return 0;
}
