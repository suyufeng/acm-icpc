#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>

using namespace std;

#define N 200005
#define PI pair<LL, LL> 
#define MP(x,y) make_pair(x,y)
#define LL long long
priority_queue<PI>Q;

pair< PI,LL> a[N];
PI tmp[N];
LL b[N],l[N],r[N],ans[N];

int main()
{
    LL n,m;
    scanf("%I64d%I64d",&n,&m);
    for(LL i=1;i<=n;i++)
        scanf("%I64d %I64d",&l[i],&r[i]);
    for(LL i=1;i<n;i++)
        a[i]=MP(MP(l[i+1]-r[i],r[i+1]-l[i]),i);
    sort(a+1,a+n);
    for(LL i=1;i<=m;i++)
        scanf("%I64d",&b[i]),tmp[i]=MP(b[i],i);
    sort(tmp+1,tmp+1+m);
    LL now=1,sum=0;
    for(LL i=1;i<=m;i++)
    {
        while(a[now].first.first<=tmp[i].first&&now<n) 
            Q.push(MP(-a[now].first.second,a[now].second)),now++;
        while(!Q.empty())
        {
            PI t=Q.top();
            if(-t.first<tmp[i].first) break;
            Q.pop();
            ans[t.second]=tmp[i].second;
            sum++;break;
        }
    }
    if(sum==n-1)
    {
        puts("Yes");
        for(LL i=1;i<n;i++)
            printf("%I64d ",ans[i]);
        puts("");
    }
    else
        puts("No");
    return 0;
}
