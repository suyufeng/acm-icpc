#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long LL;

#define N 2005
#define MOD 1000000007

int f[N][N];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	f[0][1] = 1;
	for(int i = 1; i <= k ; i++)
		for(int j = 1; j <= n; j++)
		{
			for(int ys = 1; ys * ys <= j; ys++)
				if(j % ys == 0)
				{
					f[i][j] = (f[i][j] + f[i - 1][ys]) % MOD;
					if(ys * ys != j)
						f[i][j] = (f[i][j] + f[i - 1][j / ys])%MOD;
				}
		}
	int CC = 0;
	for(int i = 1; i <= n; i++)
		CC = (CC + f[k][i]) % MOD;
	printf("%d", CC);
	return 0;
}
