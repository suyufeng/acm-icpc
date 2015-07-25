#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

#define N 200005

int num[3],n;
char s[N];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		num[s[i]-'0']++;
	printf("%d\n",abs(num[0]-num[1]));
	return 0;
}
