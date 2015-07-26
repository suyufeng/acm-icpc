#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

#define N 105

int digit[N][N];
int n,flag[N];

bool check(int x)
{
	for(int i=1;i<=n;i++)
		if((flag[i]^digit[x][i])==0)
			return false;
	return true;
}

int get()
{
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=check(i);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char c[200];
		scanf("%s",c+1);
		for(int j=1;j<=n;j++)
			digit[i][j]=c[j]-'0';
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) flag[j]=0;
		for(int j=1;j<=n;j++) flag[j]=(digit[i][j]==0);
		int CC=get();
		ans=max(ans,CC);
	}
	printf("%d\n",ans);
	return 0;
}
