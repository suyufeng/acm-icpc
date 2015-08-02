#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

vector<pair<int, int> >ans;
vector<int> Q;
#define N 100005

int degree[N], S[N], team[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &degree[i], &S[i]);
	int head = 0, tail = 0;
	for(int i = 0; i < n; i++)
		if(degree[i] == 1)
			team[++tail] = i;
	while(head < tail)
	{
		int u = team[ ++head];
		if(degree[u] == 0) continue;
		degree[S[u]]--; S[S[u]] ^= u;
		ans.push_back(make_pair(u,S[u]));
		if(degree[S[u]] == 1) 
			team[++tail] = S[u];
	}
	printf("%d\n",(int)ans.size());
	for(int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
