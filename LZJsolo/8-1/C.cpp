#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

#define N 200005

int num1[N], num2[N], a[N], b[N];

int tree[N], n, seq[N];
bool used[N];

int lowbit(int x)
{
	return x & (-x);
}

void add(int x, int y)
{
	while(x <= n)
	{
		tree[x] += y;
		x += lowbit(x);
	}
	return ;
}

int Query(int x)
{
	int ans = 0;
	while(x >= 1)
	{
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d" ,&a[i]), a[i]++;
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]), b[i]++;
	for(int i = 1; i <= n; i++)
	{
		int t = Query(a[i]);
		int now = a[i] - t;
		num1[i] = now - 1;
		add(a[i], 1);
	}
	for(int i = 1; i <= n; i++)
		tree[i] = 0;
	for(int i = 1; i <= n; i++)
	{
		int t = Query(b[i]);
		int now = b[i] - t;
		num2[i] = now - 1;
		add(b[i], 1);
	}
	for(int i = 1; i <= n; i++)
		num1[i] += num2[i];
	int k = 0;
	for(int i = n - 1; i >= 1; i--)
	{
		int limit = n - i + 1;
		num1[i] += k;
		if(num1[i] >= limit)
			k = num1[i] / limit,
			num1[i] %= limit;
		else
			k = 0;
	}
	
	for(int i = 1; i <= n; i++)
		tree[i] = 0;
	for(int i = 1; i <= n; i++)
	{
		int now = num1[i] + 1;
		int left = 1,right = n;
		int ans = 0;
		while(left <= right)
		{
			int mid = left + right >> 1;
			int t = mid - Query(mid);
			if(t == now)
			{ 
				if(used[mid] == true)
					right = mid - 1;
				else
					{ans = mid; break;}
			}
			else
			{
				if(t > now)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
		used[ans] = true;
		add(ans, 1);
		seq[i] = ans;
	}
	for(int i = 1; i <= n; i++)
		printf("%d ",seq[i] - 1);
	puts("");
	return 0;
}
