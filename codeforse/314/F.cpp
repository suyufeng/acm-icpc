#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

#define N 1000005

int num[N], a[N], base[N];
int prime[N / 10 + 5];
bool U_prime[N];

int main()
{
    int n;
    scanf("%d", &n);
    int Max = 0, cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int p; 
        scanf("%d", &p);
        a[i] = p;
        base[p]++;
        Max = max(Max, p);
    }
    for(int i = 2; i <= Max; i++)
    {
        if(!U_prime[i]) prime[++cnt] = i;
        else continue;
        for(int j = 2 * i; j <= Max; j += i)
            U_prime[j] = true;
    }   
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - a - 1;
    int ans = 0;
    num[1] = base[1];
    for(int i = 1; i <= Max; i++)
    {
        int now = i;
        for(int j = 1; now * prime[j] <= Max && j <= cnt; j++)
            num[now * prime[j]] = max(num[now * prime[j]], num[now] + base[now * prime[j]]);
    }
    for(int i = 1; i <= n; i++)
        ans = max(ans, num[a[i]]);
//  printf("%d %d %d\n", num[3], num[6], num[18]);
    printf("%d\n", ans);
    return 0;
}
