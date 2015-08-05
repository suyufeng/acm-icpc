#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

typedef long long LL;

	int n;
void work()
{
	int now = 0;
	for(;(1LL << (LL)now) <= (LL)n; now++);
	//now--;
	printf("%d\n",now);
}

int main()
{
	while(scanf("%d",&n) == 1)
			work();
	return 0;
}
