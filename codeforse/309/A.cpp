#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

#define N 25

char s[N];

struct node
{
	char c[N];
	friend bool operator < (const node &x,const node &y)
	{
		for(int i=1;i<=21;i++)
		{
			if(x.c[i]==y.c[i]) continue;
			return x.c[i]<y.c[i];
		}
		return false;
	}
};			

map<node,bool>Q;

int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	node tmp;
	memset(tmp.c,0,sizeof(tmp.c));
	int ans=0;
	for(int i=1;i<=len+1;i++)
	{
		for(int j=1;j<=26;j++)
		{
			memset(tmp.c,0,sizeof(tmp.c));
			int cnt=0;
			for(int l=1;l<i;l++) tmp.c[++cnt]=s[l];
			tmp.c[++cnt]=j+'a'-1;
			for(int l=i;l<=len;l++) tmp.c[++cnt]=s[l];
			if(Q.count(tmp))	continue;
		//	puts(tmp.c+1);
			ans++; Q[tmp]=true;
		}		
	}
	
	printf("%d\n",ans);
	return 0;
}

