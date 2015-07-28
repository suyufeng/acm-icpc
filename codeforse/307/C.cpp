#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;


#define N 100005

typedef long long LL;

LL a[N], tmp[N];

LL n, m;
bool check(LL x)
{
	LL tail = n;
	for(LL i = 1; i <= n; i++)
		tmp[i] = a[i];
	while(a[tail] == 0 && tail != 0) tail --;
	for(LL i = 1; i <= m; i++)
	{
		LL res = x - tail;
		while(res > 0)
		{
			if(tail == 0) break;
			if(res < tmp[tail])
				tmp[tail] -= res, res = 0;
			else
				res -= tmp[tail], tmp[tail] = 0, tail--;
			while(a[tail] == 0 && tail != 0) tail --;
			
		}
	}
	if(tail == 0) return true;
	else return false;
}

int main()
{
	cin >> n >> m;
	LL sum = 0;
	for(LL i = 1;  i <= n; i++)
		cin>>a[i],sum += (LL)a[i];
	sum += (LL)n * 2;
	LL l = 1, r = sum;
	LL ans = 0;
	while(l <= r)
	{
		LL mid = l + r >> 1;
		if(check(mid)) {
			ans = mid, r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout<< ans << endl;
	return 0;
}
