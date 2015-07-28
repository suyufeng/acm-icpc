#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

// 13:19

#define N 105

int a[N][N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for(int  r = x1; r <= x2 ; r++)
            for(int c = y1; c <= y2; c++)
                a[r][c]++;
    }
    int ans = 0;
    for(int i = 1;i <= 100; i++)
        for(int j = 1; j <= 100; j++)
            ans += a[i][j];
    printf("%d\n", ans);
    return 0;
}
