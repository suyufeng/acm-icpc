#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

#define N 1000005

typedef long long LL;

LL n, m, a[N];
	
struct Segtree
{
	LL lson[N << 2], rson[N << 2], sum[N << 2], Max[N << 2];
	
	void update(LL root)
	{
		sum[root] = sum[root << 1] + sum[root << 1 | 1];
		Max[root] = max(Max[root << 1], Max[root << 1 | 1]);
	}
	
	void build(LL root, LL l, LL r)
	{
		lson[root] = l, rson[root] = r;
		if(l == r)
		{
			sum[root] = a[l], Max[root] = a[l];
			return ;
		}
		LL mid = l + r >> 1;
		build(root << 1, l, mid); build(root << 1 | 1, mid + 1, r);
		update(root);
	}

	LL Query(LL root, LL l, LL r)
	{
		if(lson[root] == l && rson[root] == r)
			return sum[root];
		LL mid = lson[root] + rson[root] >> 1;
		if(l > mid) return Query(root << 1 | 1, l, r);
		else 
			if(r <= mid) return Query(root << 1, l, r);
			else
				return Query(root << 1, l, mid) + Query(root << 1 | 1, mid + 1, r);
	}
	
	void update(LL root, LL x, LL key)
	{
		if(lson[root] == x && rson[root] == x)
		{
			Max[root] = sum[root] = key;
			return ;
		}
		LL mid = lson[root] + rson[root] >> 1;
		if(x <= mid) update(root << 1, x, key);
		else 		update(root << 1 | 1, x, key);
		update(root);
	}
	
	void check(LL root, LL l, LL r, LL key)
	{
		if(Max[root] < key) return ;
		update(root, l, r, key);
		return ;
	}	
	
	void update(LL root, LL l, LL r, LL key)
	{
		if(lson[root] == rson[root])
		{	
			sum[root] %= key;
			Max[root] %= key;
		//	printf("%I64d %I64d %I64d\n", lson[root], rson[root], sum[root]);
			return ;
		}
		LL mid = lson[root] + rson[root] >> 1;
		if(l > mid) check(root << 1 | 1, l, r, key);
		else 
			if(r <= mid) check(root << 1, l, r, key);
			else
				check(root << 1, l, mid, key), check(root << 1 | 1, mid + 1, r, key);
		update(root);
	//	printf("%I64d %I64d %I64d\n", lson[root], rson[root], sum[root]);
		return ;
	}
}tree;

int main()
{
	scanf("%I64d%I64d", &n, &m);
	for(LL i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	tree.build(1, 1, n);
	for(LL i = 1; i <= m; i++)
	{
		LL type;
		scanf("%I64d", &type);
		if(type == 1)
		{
			LL l, r;
			scanf("%I64d%I64d", &l, &r);
			printf("%I64d\n", tree.Query(1, l, r));
		}
		if(type == 2)
		{
			LL l, r, x;
			scanf("%I64d%I64d%I64d", &l, &r, &x);
			tree.update(1, l, r, x);
		}
		if(type == 3)
		{
			LL x, id;
			scanf("%I64d%I64d", &x, &id);
			tree.update(1, x, id);
		}
	}
	return 0;
}
