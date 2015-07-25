#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;

#define N 200005

char s[3][N];

bool cmp(int id,int l1,int r1,int l2,int r2)
{
    int st1=l1,st2=l2;
    for(;st1!=r1+1;st1++,st2++)
    {
        if(s[id][st1]==s[id][st2]) continue;
        return s[id][st1]<s[id][st2];
    }
    return false;
}
    

void get(int id,int l,int r)
{
    if((r-l+1)&1) return ;
    if(l==r) return ;
    int mid=l+r>>1;mid++;
    get(id,l,mid-1),get(id,mid,r);
    bool t=cmp(id,l,mid-1,mid,r);
//  printf("%d %d %d %d %d\n",l,mid-1,mid,r,t);
    if(t)
    {
        int st1=l,st2=mid;
        for(;st1!=mid;st1++,st2++) swap(s[id][st1],s[id][st2]);
    }
    return ;
}

int main()
{
    scanf("%s",s[1]+1);
    scanf("%s",s[2]+1);
    get(1,1,strlen(s[1]+1));get(2,1,strlen(s[2]+1));
    int len=max(strlen(s[1]+1),strlen(s[2]+1));
    //puts(s[1]+1);puts(s[2]+1);
    for(int i=1;i<=len;i++)
        if(s[1][i]!=s[2][i])
        {
            puts("NO");
            return 0;
        }
    puts("YES");
    return 0;
}
