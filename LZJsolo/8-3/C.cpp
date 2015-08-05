#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

#define MOD 100000007
#define K 100005
#define N 105

int a[K], b[K];
int num[K], f[K];
pair<int, int> t[K];

typedef long long LL;

void work()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; i++)
		num[i] = 0;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		t[++cnt] = make_pair(a[i], b[i]);
	for(int i = 1; i <= k;i++)
		if(num[i] > 0)
			t[++cnt] = make_pair(i, num[i]);
	for(int i = 1; i <= k; i++)
		f[i] = 0;
	int tmp = cnt;
	for(int i = 1; i <= tmp; i++)
	{
		int now = 2;
		for(;(LL)t[i].first * (LL)now <= k && now * 2 <= t[i].second; now *= 2)
			t[++cnt] = make_pair(now * t[i].first, 1);
		if(t[i].second > (now - 1) && (LL)(t[i].second - (now - 1)) * t[i].first <= k)
			t[++cnt] = make_pair((t[i].second - (now - 1)) * t[i].first, 1);
	}
	f[0] = 1;
	for(int i = 1; i <= cnt; i++)
		for(int j = k; j >= t[i].first; j--)
			if(f[j - t[i].first] == 1)
				f[j] = 1;
	int CC = 0;
	for(int i = 1; i <= k;i++)
		CC += (f[i] == 1);
	printf("%d\n", CC);
	return ;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++)
		printf("Case %d: ",i), work();
	return 0;
}
