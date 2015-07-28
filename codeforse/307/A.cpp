#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>


using namespace std;
// 8:56


int a[2005],b[2005];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), a[i] = n - a[i] + 1;
	for(int i = 1; i <= n; i++)
		b[i] = a[i];
	sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; i++)
		printf("%d ", lower_bound(b + 1, b + 1 + n, a[i]) - b);
	puts("");
	return 0;
}
