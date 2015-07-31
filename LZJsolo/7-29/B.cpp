#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define N 1005

int a[N];

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		ans += min(a[p], a[q]);
	}
	printf("%d\n", ans);
	return 0;
}
