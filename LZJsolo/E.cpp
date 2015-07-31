#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<vector>

using namespace std;

#define N 100005

typedef long long LL;

vector<LL> Q[N];

LL a[N];

int main()
{
	LL k, n;
	vector <LL> tmp;
	scanf("%I64d %I64d", &k, &n);
	for(LL i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	a[0] = -1;
	for(LL i = 1; i <= n; i++)
		if(a[i] != a[i - 1])
			tmp.push_back(a[i]);
	n = tmp.size();
	for(int i = 1; i <= n; i++)
		a[i] = tmp[i - 1];
	for(LL i = 1; i <= n; i++)
	{
		if(i != 1) Q[a[i]].push_back(a[i - 1]);
		if(i != n) Q[a[i]].push_back(a[i + 1]);
	}
	for(LL i = 0; i <= k; i++)
		sort(Q[i].begin(), Q[i].end());
	LL ans = 0, Max = 0, Maxid, become;
	for(LL i = 0; i <= k; i++)
	{
		LL last = 0;
		if(Q[i].size() == 0) continue;
		for(LL j = 0; j < Q[i].size(); j++)
			last += abs(Q[i][j] - i);
		LL t = (Q[i].size() - 1) >> 1;
		for(LL j = 0; j < Q[i].size(); j++)
			last -= abs(Q[i][j] - Q[i][t]);
		if(Max < last)
			Max = last, Maxid = i, become = Q[i][t];
	}
	for(LL i = 1; i <= n; i++)
		if(a[i] == Maxid)
			a[i] = become;
	for(LL i = 2; i <= n; i++)
		ans += abs(a[i] - a[i - 1]);
	cout << ans << endl;
	return 0;
}
