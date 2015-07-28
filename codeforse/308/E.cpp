#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

//12:02;

#define N 5001

typedef long long LL;

char c[N];
int n;
LL tmp;

LL calc(int x,int y,int l,int r)
{
    stack<LL>seq;
    if(y<x) return 1;
    if(y<0) return 1;
    if(x<0) return 1;
    if(x>n||y>n) return 1;
    for(int i = x;i <= y;i ++)
    {
        if(i == l)
        {
            i = r; seq.push(tmp);
            continue;
        }
        if(c[i] == '+') continue;
        if(c[i] == '*')
        {
            i++;    
            LL t=seq.top();seq.pop();
            if(i == l)
                seq.push(tmp*t),i=r;
            else
                seq.push((c[i]-'0')*t);
        }
        else
            seq.push(c[i]-'0');
    }
    LL CC=0;
    while(!seq.empty())
    {
        CC+=seq.top();
        seq.pop();
    }
    return CC;
}

int main()
{
    scanf("%s",c+1);
    n=strlen(c+1);
    vector<int> mul;mul.push_back(0);
    for(int i = 1; i <= n; i++)
        if(c[i] == '*') mul.push_back(i);
    mul.push_back(n+1);
    LL Max=calc(1,n,0,0);
    for(int i=0;i<mul.size();i++)
        for(int j=i+1;j<mul.size();j++)
        {
            tmp=calc(mul[i]+1,mul[j]-1,0,0);
            LL CC=calc(1,n,mul[i]+1,mul[j]-1);
            Max=max(Max,CC);
        }
    printf("%I64d\n",Max);
    return 0;
}
