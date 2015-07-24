#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
	int a[8];
	for(int i=1;i<=6;i++)
		scanf("%d",&a[i]);
	int last=a[1],now=0,ans=0;
	for(int i=2;i<=a[2]+a[3]+1;i++)
	{
		now=last;
		if(i<=a[2]+1&&i<=a[6]+1) now++;
		if(i>a[2]+1&&i>a[6]+1) now--;
		ans+=(last+now);
		last=now;
	}
	printf("%d\n",ans);
	return 0;
}
