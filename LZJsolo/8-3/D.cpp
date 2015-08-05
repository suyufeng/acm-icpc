#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>

using namespace std;

#define MOD 100000007
#define K 1005
#define N 55

typedef long long LL;

map<int,int> Q;

int a[N], b[N];
int f[N][K];
bool flag;
int n, k, need[N];

int limit = 0;

void out(int x)
{
	LL CC = 0;
	for(int i = 1; i <= x - 1; i++)
		if(need[i])
			CC += (LL)need[i] * a[i];
	//printf("%lld\n", CC);
	if(x <= n / 2 + 1)
		Q[CC] = 1;
	if(CC == (LL)k)
		flag = true;
	if(CC > k) return ;
	if(x > limit)
		if(Q.count(k - CC))
			flag = true;
	return ;
}

void dfs(int x)
{
	if(x > limit) 
	{
		out(x); return ;
	}
	need[x] = 2; dfs(x + 1);
	need[x] = 1; dfs(x + 1);
	need[x] = 0; dfs(x + 1);
	return ;
}		

void work()
{
	scanf("%d%d", &n, &k);
	Q.clear();
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	flag = false;
	limit = n / 2;
	dfs(1);
	limit = n;
	dfs(n / 2 + 1);
	if(flag == 1)
		puts("Yes");
	else
		puts("No");
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++)
		printf("Case %d: ",i), work();
	return 0;
}
