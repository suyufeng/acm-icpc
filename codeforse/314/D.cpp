#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

#define N 200005

int n, m;   

struct B
{
    int f[N];
    void get()
    {
        for(int i = 1; i <= n; i++)
            f[i] = i;
        return ;
    }
    int find(int x)
    {
        if(x == f[x]) return f[x];
        f[x] = find(f[x]);
        return f[x];
    }
    
    void hb(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if(fx == fy) return ;
        f[fx] = fy;
    }
    
    bool check(int x, int y)
    {
        int fx = find(x), fy = find(y);
        return fx == fy;
    }
}f,g;
        

int main()
{
    scanf("%d%d", &n, &m);
    f.get(), g.get();
    for(int i = 1; i <= m; i++)
    {
        int x, y, type;
        scanf("%d%d%d", &type, &x, &y);
        if(type == 2)
        {
            for(int now  = x, last = 0; now <= y; now = g.f[now] + 1)
            {
                if(last != 0)  g.hb(last, now),f.hb(last, now);
                last = now;
            }
        }
        if(type == 1)
        {
            f.hb(x, y);
        }
        if(type == 3)
        {
            if(f.check(x, y))
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}   
