#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

#define N 1005

int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    int num = 0;
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), num += (a[i] == 1);
    if(!num)
        puts("1");
    else
        puts("-1");
    return 0;
}
