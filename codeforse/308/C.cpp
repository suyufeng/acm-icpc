#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>

//12:51~12:54

using namespace std;

int main()
{
    int w, m;
    scanf("%d%d", &w, &m);
    if(w == 2)
    {
        puts("YES");
        return 0;
    }
    vector<int> digit;
    while(m)
    {
        digit.push_back(m % w);
        m /= w;
    }
    digit.push_back(0);
    for(int i = 0; i < digit.size(); i++)
    {
        if(digit[i]<=1) continue;
        if(digit[i] == w - 1)
        {
            i ++;
            while(digit[i] == w - 2 || digit[i] == w - 1) i ++;
            if(digit[i] != 0)
            {
                puts("NO"); return 0;
            }
            continue;
        }
        puts("NO"); return 0;
    }
    puts("YES");
    return 0;
}
