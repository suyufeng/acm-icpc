#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

int n,a[100005];
int get(int x)
{
    if(x<0) return x+n;
    if(x>=n) return x-n;
    return x;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(j&1)
                a[j]=get(a[j]+1);
            else
                a[j]=get(a[j]-1);
        bool flag=false;
        for(int j=1;j<=n;j++)
            if(a[j]!=(j-1))
            { flag=true; break;}
        if(!flag)
        {
            puts("Yes");return 0;
        }   
    }
    puts("No");
    return 0;
}
