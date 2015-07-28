#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>

using namespace std;

//12:20 ~ 12:29

#define N 2005
#define MP make_pair
#define eps 1e-10

typedef long long LL;

pair<LL,LL> p[N];
vector<pair<LL,LL> > T;

double get(pair<LL,LL>x, pair<LL,LL>y)
{
    pair<LL,LL> t=MP(x.first-y.first,x.second-y.second);
    if(t.first == 0) t.second = abs(t.second);  
    if(t.second == 0) t.first = abs(t.first);
    if(t.first * t.second > 0) t.first=abs(t.first), t.second = abs(t.second);
    if(t.first * t.second < 0) t.first=abs(t.first), t.second = -abs(t.second);
    return atan2(t.second,t.first);
}

bool equal(double x,double y)
{
    return fabs(x-y)<eps;
}

int main()
{
    LL n;
    scanf("%I64d",&n);
    for(LL i=1;i<=n;i++)
    {
        LL p,q;
        scanf("%I64d %I64d",&p,&q);
        T.push_back(make_pair(p,q));
    }   
    LL ans = 0;
    for(LL i = 0; i < T.size(); i++)
    {
        vector<double> ang;
        for(LL j = 0;j < T.size(); j++)
            if(T[i] != T[j])
                ang.push_back(get(T[i],T[j]));
        ans += (n - 1) * (n - 2);
        LL num = 1;
        sort(ang.begin(),ang.end());
        for(LL j = 1;j < ang.size(); j++)
            if(!equal(ang[j],ang[j-1]))
                ans -= num * (num - 1), num = 1;
            else
                num ++;
        ans -= num * (num - 1);
    }
    printf("%I64d\n", ans/6);
    return 0;
}
