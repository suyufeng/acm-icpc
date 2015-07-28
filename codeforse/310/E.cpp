#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

char type[5];

#define N 200005

int tmp[N<<1],di[266];

struct node
{
	int x,y,flag;
	node(){}
	node(int x,int y,int falg):x(x),y(y),flag(flag){}
}work[N];

int get(int x)
{
	return lower_bound(tmp+1,tmp+1+tmp[0],x)-tmp;
}

struct Tree
{
	int L[N<<3],R[N<<3],now[N<<3],Max[N<<3];
	bool flag[N<<3];
	void build(int root,int l,int r)
	{
		L[root]=l;R[root]=r;Max[root]=0;flag[root]=0;
		if(l==r) return ;
		int mid=l+r>>1;
		build(root<<1,l,mid),build(root << 1 | 1, mid + 1, r);	
	}
	
	void update(int root, int key)
	{
		flag[root] = true;
		Max[root] = max(Max[root], key);
		now[root] = max(now[root], key);
	}
	
	void push_down(int root)
	{
		if(flag[root]) return ;
		flag[root]=false;
		update(root << 1, now[root]), update(root << 1 | 1, now[root]);
		now[root] = flag[root] = 0;
		return ;
	}
	void insert(int root, int l, int r, int key)
	{
		if(l == L[root] && r == R[root])
		{
			update(root, key);
			return ;
		}		
		push_down(root);
		int mid = L[root] + R[root] >> 1;
		if(mid < l)
			insert(root << 1 | 1, l, r, key);
		else
			if(mid >= r)
				insert(root << 1, l, r, key);
			else
				insert(root << 1, l, mid, key),insert(root << 1 | 1, mid + 1, r, key);
		Max[root] = max(Max[root << 1], Max[root << 1 | 1]);
	}
	int Query(int root, int l)
	{
		if(L[root] == R[root]) return Max[root];
		push_down(root);
		int mid = L[root] + R[root] >> 1;
		if(mid < l) 
			return Query(root << 1 | 1, l);
		else
			return Query(root << 1, l);
	}
}tree[3];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	di['U']=1;di['L']=2;
	for(int i=1;i<=m;i++)
	{
		int p,q;
		scanf("%d%d",&p,&q);tmp[++tmp[0]]=p,tmp[++tmp[0]]=q;
		scanf("%s",type+1);
		work[i]=node(p,q,di[type[1]]);
	}
	sort(tmp+1,tmp+1+tmp[0]);
	tmp[0]=unique(tmp+1,tmp+1+tmp[0])-tmp-1;
	for(int i=1;i<=2;i++)
		tree[i].build(1, 1, tmp[0]);
	for(int i = 1; i <= m; i++)
	{
		if(work[i].flag == 1)
		{
			int p = get(work[i].x);
			int q = get(work[i].y);
			int t = tree[2].Query(1, p);
			printf("%d\n", work[i].y - seq[t]);
			tree[2].insert(1, p, q, t);
			tree[1].insert(1, p, q, p);	
		}
	}
	return 0;
}
