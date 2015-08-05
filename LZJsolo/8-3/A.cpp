#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

#define MOD 100000007
#define K 1005
#define N 55

int a[N], b[N];
int f[N][K];

void work()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);	
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= k; j++)
			for(int t = 0; t * a[i] <= j && t <= b[i]; t++)
				f[i][j] = (f[i][j] + f[i - 1][j - t * a[i]]) % MOD;
	printf("%d\n", f[n][k]);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++)
		printf("Case %d: ",i), work();
	return 0;
}
