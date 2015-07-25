#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

#define N 10

pair<int, int>a[N], b[N];

int main()
{
    for(int i = 1; i <= 3; i++)
        scanf("%d %d",&a[i].first, &a[i].second);
    for(int i = 0; i < 8; i++)
    {
        for(int j = 1; j <= 3; j++)
            b[j] = a[j];
        for(int j = 1; j <= 3; j++)
            if(i >> (j - 1) & 1)
                swap(b[j].first, b[j].second);
        if(b[1].first >= b[2].first + b[3].first && b[1].second >= max(b[2].second, b[3].second))
            puts("YES"),exit(0);
        if(b[1].second >= b[2].second + b[3].second && b[1].first >= max(b[2].first, b[3].first))
            puts("YES"),exit(0);
    }
    puts("NO");
    return 0;
}
