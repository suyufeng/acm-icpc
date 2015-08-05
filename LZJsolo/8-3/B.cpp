#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

#define MOD 100000007
#define K 10005
#define N 105

int a[N], b[N];
int f[K];

void work()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= k; j++)
			if( j >= a[i])
				f[j] = (f[j] + f[j - a[i]]) % MOD;
	printf("%d\n", f[k]);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++)
		printf("Case %d: ",i), work();
	return 0;
}
