#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define N 205

int tmp[N], a[N];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ans = -0x3f3f3f3f;
	for(int l = 1; l <= n; l++)
		for(int r = l; r <= n; r++)
		{
			int CC = 0;
			for(int i = 1; i <= n; i++)
					tmp[i] = a[i];
			for(int id = 1; id <= k; id++)
			{
				int Max = -0x3f3f3f3f, Maxid = 0;
				int Min = 0x3f3f3f3f, Minid = 0;
				for(int i = 1; i <= l - 1; i++)
					if(tmp[i] > Max)
						Max = tmp[i], Maxid = i;
				for(int i = r + 1; i <= n; i++)
					if(tmp[i] > Max)
						Max = tmp[i], Maxid = i;
				for(int i = l; i <= r; i++)
					if(tmp[i] < Min)
						Min = tmp[i], Minid = i;
				if(Max > Min)
					swap(tmp[Maxid], tmp[Minid]);
			}
			for(int i = l; i <= r; i++)
				CC += tmp[i];
			ans = max(ans, CC);
		}
	printf("%d\n", ans);
	return 0;
}

