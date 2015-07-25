#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;

vector<pair<int ,int> >ans;
#define MP(x,y) make_pair(x,y)
int main()
{
    int n,m;
    int CC=0;
    scanf("%d%d",&n,&m);
    CC=2*n-m-1;
    for(int i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        vector<int>seq;
        for(int j=1;j<=t;j++)
        {
            int p;scanf("%d",&p);
            seq.push_back(p);
        }
        for(int j=0,l;j<seq.size();j=l)
        {
            for(l=j+1;l<seq.size()&&seq[l]==(seq[l-1]+1);l++);
            ans.push_back(MP(seq[j],l-j));
        }
    }
    sort(ans.begin(),ans.end());
    CC-=2*(ans[0].second-1);
    printf("%d\n",CC);
    return 0;
}
