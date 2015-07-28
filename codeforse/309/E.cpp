#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>


using namespace std;

#define PI pair<int, int>
#define INF 0x3f3f3f3f
#define N 105
#define MP make_pair

char type[N];
PI g[N][N], tmp[N][N];

vector<pair<PI, PI> > Q;

PI operator + (const PI &x,const PI &y)
{
	return MP(x.first + y.first, min(x.second, y.second));
}

int get()
{
	int len = strlen(type + 1);
	int CC = 0;
	for(int i = 1; i <= len; i++)
		CC = CC * 10 + (type[i] - '0');
	return CC;
}

void out(PI x)
{
	if(x.first == INF)
		printf("($,<)");
	else
		if(x.second == 0)
			printf("(%d,<)",x.first);
		else
			printf("(%d,<=)",x.first);
	return ;
}

void work()
{
	Q.clear();
	int n=0;
	while(1)
	{
		scanf("%s",type + 1);
		if(type[1] == '#') break;
		int xi=get(), xj;
		int key, flag;	
		scanf("%d%d%d", &xj, &key, &flag);
		n = max(n, xi + 1),n = max(n, xj + 1);
		if(flag != 0) flag = 1;
		if(flag == 0) flag = 1, key--;
		if(xi == xj)
		{
			if(MP(key, flag) < MP(0, 1))
			{	puts("Canonical DBM does not exist."); puts(""); return ;}
			else	
				continue;
		}
		Q.push_back(MP(MP(xi + 1, xj + 1), MP(key, flag)));
	}
	for(int i= 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j)
				g[i][j] = tmp[i][j] = MP(INF, INF);
			else
				g[i][j] = tmp[i][j] = MP(0, 1);
	for(int i = 0; i < Q.size(); i++)
	{
		pair<PI, PI>tt;
		tt=Q[i];
		g[tt.first.first][tt.first.second] = tmp[tt.first.first][tt.first.second] = min(g[tt.first.first][tt.first.second], tt.second);
	}	
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(g[i][k].first != INF && g[k][j].first != INF)
					g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
		
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(tmp[i][j] != MP(INF, INF) && i != j)
			{
				PI k = g[j][i];
				k.first *= -1;
				if(k.second == 0) k.second = INF;
				if(k > tmp[i][j])
				{	
					puts("Canonical DBM does not exist."); 
					puts(""); return ;
				}
			}	
		}
	for(int i = 1; i <= n; i++, puts(""))
	{
		for(int j = 1;j <= n - 1; j++) 
			out(g[i][j]), printf(" ");
		out(g[i][n]); printf(" ");
	}
	puts("");		return ;
}

int main()
{
	int tests = 0;
	scanf("%d",&tests);
	for(int te = 1; te <= tests; te++)
	{
		printf("Case %d:\n", te);
		work();
	}
	return 0;
}
