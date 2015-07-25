#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

#define N 2005
#define M 200005
#define MOD 1000000007

int jc[M], ni[M], f[N];
pair<int, int>a[N];

int times(int x, int y)
{
	return 1LL * x * y % MOD;
}

int pow(int x, int y)
{
	int ans = 1;
	for(; y; y >>= 1, x = times(x, x))
		if(y & 1)
			ans = times(ans, x);
	return ans;
}

int C(int x, int y)
{
	x += y;
	if(x < 0 || y < 0) return 0;
	if(y > x) return 0;
	return times(jc[x], times(ni[y], ni[x - y]));
}

pair<int, int> operator - (pair<int, int> x, pair<int, int> y)
{
	return make_pair(x.first - y.first, x.second - y.second);
}

int del(int x, int y)
{
	x -= y;
	if(x < 0) x += MOD;
	return x;
}

int main()
{
	int h, w;
	scanf("%d%d", &h, &w);h, w;
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].first, &a[i].second);
	jc[0] = ni[0] = 1;
	for(int i = 1; i <= 200000; i++)
		jc[i] = times(jc[i-1], i);
	for(int i = 1; i <= 200000; i++)
		ni[i] = pow(jc[i], MOD - 2);
	sort(a + 1, a + 1 + n);
	int ans = C(h - 1, w - 1);
	for(int i = 1; i <= n; i++)
	{
		f[i] = C(a[i].first - 1, a[i].second - 1);
	//	printf("%d\n", f[i]);
		for(int j = 1; j < i; j++)
		{
			pair<int, int> tmp = a[i] - a[j];
			f[i] = del(f[i], times(f[j], C(tmp.first, tmp.second)));
		}
		pair<int, int> tmp = make_pair(h, w) - a[i];
	//	printf("%d %d %d\n", tmp.first + tmp.second, tmp.first, C(tmp.first, tmp.second));
		ans = del(ans, times(f[i], C(tmp.first, tmp.second)));
	}
	printf("%d\n", ans);
	return 0;
}
