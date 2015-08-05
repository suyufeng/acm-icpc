#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

typedef long long LL;

	LL n;
void work()
{
	LL sum = 0, cnt = 1, now = 1;
	while(1)
	{
		sum += now;
		if(sum >= n) break;
		now *= 3; cnt ++;
	}
	printf("%d\n", cnt);
}

int main()
{
	while(cin >> n)
			work();
	return 0;
}
