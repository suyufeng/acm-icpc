#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>


using namespace std;

// 9:09~9:25

#define N 400005


char c[N],b[N],a[N];

int num[7][N];

void copy(int x,int y)
{
    for(int i = 1; i <= 26; i++)
        num[y][i] = num[x][i];
    return ;
}

int work(int x, int y, int k)
{
    int Min = 1000000;
        for(int i = 1;i <= 26; i++)
            if(num[y][i])
                Min = min(Min, num[x][i] / num[y][i]);
    for(int i = 1; i <= 26; i++)
        num[x][i] -= (num[y][i] * k);
    return Min;
}

void print(int x, int y)
{
    if(x == 1)
    {
        for(int i = 1; i <= 26; i++)
            for(int j = 1; j <= num[1][i]; j++)
                printf("%c", i + 'a' - 1);
        return ;
    }
    if(x == 2)
        for(int i = 1; i <= y; i++)
            printf("%s", b + 1);
    if(x == 3)
        for(int i = 1; i <= y; i++)
            printf("%s", c + 1);
    return ;
}

int main()
{
    scanf("%s",a+1);
    int len = strlen(a + 1);
    for(int i = 1; i <= len; i++) 
        num[1][a[i] - 'a' + 1]++;
    scanf("%s",b+1);
    len = strlen(b + 1);
    for(int i = 1; i <= len; i++)
        num[2][b[i] - 'a' + 1]++;
    scanf("%s",c+1);
    len = strlen(c + 1);
    for(int i = 1; i <= len; i++)
        num[3][c[i] - 'a' + 1]++;
    copy(1, 4);
    int t1=work(1, 2, 0);
    int Max = 0, Maxid = 0;
    for(int i = 0; i <= t1; i++)
    {
        copy(4, 1);work(1, 2, i);
        int t2 = work(1, 3, 0);
        if(t2 + i > Max)
            Max = t2 + i, Maxid = i;
    }
    copy(4, 1);
    int rat = work(1, 2, Maxid);
    print(2, Maxid);
    rat = work(1, 3, Max - Maxid);
    print(3, Max - Maxid);
    print(1 ,1);
    puts("");
    return 0;
}
