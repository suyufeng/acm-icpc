#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

typedef long long LL;

int t[11];
int num[11];

//13:14~13:15

int main()
{
    t[1] = 1;
    for(int i = 2; i <= 10; i++)
        t[i] = t[i - 1] * 10;
    int n;
    scanf("%d", &n);
    LL ans = 0;
    for(int i = 10; i >= 1; i--)
        if(n >= t[i])
            ans += (LL)(n - t[i] + 1) * i , n = t[i] - 1;
    printf("%I64d\n", ans);
    return 0;
}
