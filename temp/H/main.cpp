#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int path[40];
double dp[40];

int main()
{
    memset(path, 0, sizeof(path));
    memset(dp, 0, sizeof(dp));
    path[1] = 1;
    for(int i=2; i<31; i++)
    {
        path[i] = path[i-1] * 2 + 1;
    }

    dp[1] = 0.67;
    for(int i=2; i<31; ++i)
    {
        dp[i] = dp[i-1]/3.0 + 2 * (dp[i-1] + 1 + path[i-1]) / 3;
    }
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int a;
        scanf("%d", &a);
        printf("%.2f\n", dp[a]);
    }

    return 0;
}