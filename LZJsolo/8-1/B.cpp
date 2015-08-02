#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

#define N 30005
#define M 520

int f[N][M];
int num[N];

int main()
{
	int n ,d ,Max=0;
	scanf("%d %d", &n, &d);
	for(int i = 1; i <= n; i++)
	{
		int p;
		scanf("%d", &p);
		Max = max(Max, p);
		num[p] ++;
	}
	int sum = d, l, r;
	for(l = d - 1;sum <= Max && l >= 1; sum += l, l--);
	sum = d;
	for(r = d + 1;sum <= Max; sum += r, r++);
	l--; r++;
	l = max(1, l); r = min(Max, r);
	for(int i = 1; i <= Max; i++)
		for(int j = 1; j <= r - l + 1; j++)
			f[i][j] = -1;
	//printf("%d\n",d);
	f[d][d - l + 1] = num[d];
	int CC = 0;
	for(int i = d;i <= Max;i++)
		for(int j = 1; j <= r - l + 1; j++)
			if(f[i][j] != -1)
			{
				CC = max(CC ,f[i][j]);
				if(j != 1 && i + j + l - 2 <= Max)
				{
					f[i + j + l - 2][j - 1] = max(f[i + j + l - 2][j - 1] ,max(0, f[i][j]) + num[i + j + l - 2]); 
					//intf("%d %d\n", i,i + j + l - 2);
				} 
				if(j != Max && i + j + l<= Max)
				{
						//printf("%d %d\n", i,i + j + l);
				
						f[i + j + l][j + 1] = max(f[i + j + l][j + 1], max(0, f[i][j]) + num[i + j + l]);
				}
				if(i + j + l - 1<= Max)
				{
					f[i + j + l - 1][j] = max(f[i + j + l - 1][j], max(0, f[i][j]) + num[i + j + l - 1]);
					//	printf("%d %d\n", i,i + j + l - 1);
				
				}
			}
	/*for(int i = d; i <= Max; i++)
		for(int j = 1; j <= r - l + 1; j++)
			printf("%d %d %d\n",i ,j + l - 1, f[i][j]);
	//printf("%d %d %d\n", f[*/
	printf("%d\n", CC);
	return 0;
}
