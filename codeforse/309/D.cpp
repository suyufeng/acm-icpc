#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long LL;

#define N 55

LL k,n,f[N];

int main()
{	
	cin>>n>>k;
	f[1]=1;f[2]=2;
	for(int i=3;i<=50;i++)
		f[i]=f[i-1]+f[i-2];
	for(int i=1;i<=n;i++)
	{
		if(i==n)
		{
			printf("%d ",i);
			continue;
		}
		else
		if(f[n-i]<k)
		{
			k-=f[n-i];
			i++;
			printf("%d %d ",i,i-1);
		}
		else
		printf("%d ",i);
	}
	puts("");
	return 0;
}
		
