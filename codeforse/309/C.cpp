#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define MOD 1000000007
#define N 1005
typedef long long LL;

int times(int x,int y)
{
	return ((LL)x*(LL)y)%MOD;
}

int jc[N],ni[N],a[N];

int pow(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=times(x,x))
		if(y&1)
			ans=times(ans,x);
	return ans;
}

int C(int x,int y)
{
	return times(jc[x],times(ni[y],ni[x-y]));
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	jc[1]=1;jc[0]=ni[0]=1;
	for(int i=2;i<=1000;i++) jc[i]=times(jc[i-1],i);	
	for(int i=1;i<=1000;i++) ni[i]=pow(jc[i],MOD-2);
	int sum=0;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		ans=times(ans,C(sum-1,a[i]-1));
	}
	printf("%d\n",ans);
	return 0;
}
